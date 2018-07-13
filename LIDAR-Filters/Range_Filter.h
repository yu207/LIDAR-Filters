#pragma once
#include <cfloat>

class Range_Filter
{
private:
	float filter_max;
	float filter_min;

public:
	Range_Filter();
	Range_Filter(float min, float max);
	~Range_Filter();

	float* update(float *data, int size);
	void set_max(float max);
	void set_min(float min);
	float get_max();
	float get_min();
};

