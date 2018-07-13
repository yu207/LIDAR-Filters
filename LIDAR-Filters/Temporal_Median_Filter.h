#pragma once
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Temporal_Median_Filter
{
private:
	int N_size;
	int D_size;
	vector<queue<float>> past_scan;
	vector<multiset<float>> past_scan_sorted;

public:
	Temporal_Median_Filter();
	Temporal_Median_Filter(int N, int D);
	~Temporal_Median_Filter();

	float* update(float* data, int size);
	void set_D(int D);
	int get_D();
	int get_N();
};

