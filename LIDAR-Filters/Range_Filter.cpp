#include "Range_Filter.h"

Range_Filter::Range_Filter()
{
	this->filter_min = -FLT_MAX;
	this->filter_max = FLT_MAX;
}

Range_Filter::Range_Filter(float min, float max)
{
	this->filter_min = min;
	this->filter_max = max;
}

Range_Filter::~Range_Filter()
{
}

float* Range_Filter::update(float * data, int size)
{
	if (size == 0) { return nullptr; }
	for (int i = 0; i < size; i++) {
		if (data[i]<this->filter_min) {
			data[i] = filter_min;
		}
		else if (data[i]>this->filter_max) {
			data[i] = filter_max;
		}
	}
	return data;
}

void Range_Filter::set_max(float max)
{
	this->filter_max = max;
}

void Range_Filter::set_min(float min)
{
	this->filter_min = min;
}

float Range_Filter::get_max()
{
	return this->filter_max;
}

float Range_Filter::get_min()
{
	return this->filter_min;
}

