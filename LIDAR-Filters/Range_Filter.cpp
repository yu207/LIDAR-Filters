////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	Range_Filter.cpp
//
// summary:	Implements the range filter class.
//			The Range Filter accepts a single scan data and crops the data that are outside of the
//			specified range.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Range_Filter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. 
/// 			For the case where no parameters are provided. Default range is [-FLT_MAX,FLT_MAX],
/// 			so no filtering. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Range_Filter::Range_Filter()
{
	this->filter_min = -FLT_MAX;
	this->filter_max = FLT_MAX;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. 
/// 			Overloaded constructor with user specified range. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="min">	The minimum. </param>
/// <param name="max">	The maximum. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Range_Filter::Range_Filter(float min, float max)
{
	this->filter_min = min;
	this->filter_max = max;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. 
/// 			No dynamic memory allocation, so this does nothing. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Range_Filter::~Range_Filter()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resets this object. 
/// 			Reinitialize the filter object with a new range. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="min">	The minimum. </param>
/// <param name="max">	The maximum. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Range_Filter::reset(float min, float max)
{
	this->filter_min = min;
	this->filter_max = max;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the given data.
/// 			Crops the data so it stays in the range. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="data"> A reference to the vector of the single scan data. </param>
///
/// <returns>	A reference to the filtered data. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

vector<float>& Range_Filter::update(vector<float>& data)
{
	if (data.empty()) { return data; }
	for (int i = 0; i < data.size(); i++) {
		//if data < min, let data = min;
		if (data[i]<this->filter_min) {
			data[i] = filter_min;
		}
		//if data > max, let data = max;
		else if (data[i]>this->filter_max) {
			data[i] = filter_max;
		}
	}
	return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a maximum. 
/// 			For only adjust the maximum. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="max">	The maximum. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Range_Filter::set_max(float max)
{
	this->filter_max = max;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a minimum. 
/// 			For only adjust the minimum </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <param name="min">	The minimum. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Range_Filter::set_min(float min)
{
	this->filter_min = min;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the maximum. 
/// 			Gets the current maximum setting. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <returns>	The calculated maximum. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float Range_Filter::get_max()
{
	return this->filter_max;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the minimum. 
/// 			Gets the current minimum setting. </summary>
///
/// <remarks>	Ruikun, 7/15/2018. </remarks>
///
/// <returns>	The calculated minimum. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

float Range_Filter::get_min()
{
	return this->filter_min;
}

