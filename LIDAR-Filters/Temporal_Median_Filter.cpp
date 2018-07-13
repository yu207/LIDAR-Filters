#include "Temporal_Median_Filter.h"

Temporal_Median_Filter::Temporal_Median_Filter()
{
	this->D_size = 1;
}

Temporal_Median_Filter::Temporal_Median_Filter(int N, int D)
{
	this->N_size = N;
	this->D_size = D + 1;
	this->past_scan = vector<queue<float>>(N, queue<float>());
	this->past_scan_sorted = vector<multiset<float>>(N, multiset<float>());
}

Temporal_Median_Filter::~Temporal_Median_Filter()
{
}

float * Temporal_Median_Filter::update(float * data, int size)
{
	if (size == 0) { return nullptr; }
	for (int i = 0; i < size; i++) {
		queue<float> &p = this->past_scan[i];
		multiset<float> &p_sorted = this->past_scan_sorted[i];
		p.push(data[i]);
		p_sorted.insert(data[i]);
		if (p.size() > this->D_size) {
			p_sorted.erase(p_sorted.lower_bound(p.front()));
			p.pop();
		}
		multiset<float>::iterator mid = next(p_sorted.begin(), p_sorted.size() / 2);
		data[i] = ((*mid + *prev(mid, 1 - p_sorted.size() % 2)) / 2);
	}
	return data;
}

void Temporal_Median_Filter::set_D(int D)
{
	this->D_size = D;
}

int Temporal_Median_Filter::get_D()
{
	return this->D_size;
}

int Temporal_Median_Filter::get_N()
{
	return this->N_size;
}
