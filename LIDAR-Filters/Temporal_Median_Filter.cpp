////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	Temporal_Median_Filter.cpp
//
// summary:	Implements the temporal median filter class
//			The Temporal Median Filter accepts a single scan data and filter each data point with a
//			rolling median filter of a past scan window of size D. If number of past scan is less
//			than D, the filtered data will be the median of current past window.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Temporal_Median_Filter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. 
/// 			For the case where no window size is provided. Default D_size is 1, so no filtering.
/// 			</summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Temporal_Median_Filter::Temporal_Median_Filter()
{
	this->D_size = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. 
/// 			A overloaded constructor with user specified N and D values. It also initializes
/// 			past_scan and past_scan_sorted with N. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="N">	An int to process. </param>
/// <param name="D">	An int to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Temporal_Median_Filter::Temporal_Median_Filter(int N, int D)
{
	this->N_size = N;
	this->D_size = D + 1;
	this->past_scan = vector<queue<float>>(N, queue<float>());
	this->past_scan_sorted = vector<multiset<float>>(N, multiset<float>());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Temporal_Median_Filter::~Temporal_Median_Filter()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets this object. 
/// 			Reinitialize the filter with new N and D values. It also reinitializes
/// 			past_scan and past_scan_sorted with N.</summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="N">	An int to process. </param>
/// <param name="D">	An int to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Temporal_Median_Filter::reset(int N, int D)
{
	this->N_size = N;
	this->D_size = D + 1;
	this->past_scan.clear();
	this->past_scan_sorted.clear();
	this->past_scan = vector<queue<float>>(N, queue<float>());
	this->past_scan_sorted = vector<multiset<float>>(N, multiset<float>());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the given data.
/// 			Filter the data with a rolling median of past D scans. Using a queue to maintain the 
/// 			FIFO order of past D scans. Using a multiset to maintain a window of sorted past 
/// 			D scans, median is the mid number. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="data"> A reference to the vector of the single scan data. </param>
///
/// <returns>	A reference to the filtered data. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

vector<float>& Temporal_Median_Filter::update(vector<float> &data)
{
	if (data.empty()) { return data; }
	for (int i = 0; i < data.size(); i++) {
		//retrieve the corresponding past_scan and past_scan_sorted
		queue<float> &p = this->past_scan[i];
		multiset<float> &p_sorted = this->past_scan_sorted[i];
		//add in new data to the past scan window
		p.push(data[i]);
		p_sorted.insert(data[i]);
		//if current window size exceeds D, remove oldest element from window
		if (p.size() > this->D_size) {
			p_sorted.erase(p_sorted.lower_bound(p.front()));
			p.pop();
		}
		//determine the median of the past scan window
		multiset<float>::iterator mid = next(p_sorted.begin(), p_sorted.size() / 2);
		data[i] = ((*mid + *prev(mid, 1 - p_sorted.size() % 2)) / 2);
	}
	return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the size of the rolling window of past scans. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="D">	An int to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Temporal_Median_Filter::set_D(int D)
{
	this->D_size = D;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the current setting of the size of the rolling window of past scans. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <returns>	The d. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Temporal_Median_Filter::get_D()
{
	return this->D_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the current setting of the size of a single scan. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <returns>	The n. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Temporal_Median_Filter::get_N()
{
	return this->N_size;
}
