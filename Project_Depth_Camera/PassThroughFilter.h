/**
* @file PassThroughFilter.h
* @Author Hakam Chedo (152120181096)
* @date 15 Dec 2021
* @brief This class is if at least one of the x, y and z values of the point is outside the limits, that point is removed from the point cloud.
*
* Detailed description of file.
*/
#pragma once
#ifndef PassThroughFilter_h
#define PassThroughFilter_h
#include "PointCloudFilter.h"

//! PassThroughFilter Class.
/*!
This class is if at least one of the x, y and z values of the point is outside the limits, that point is removed from the point cloud.
*/
class PassThroughFilter : public PointCloudFilter
{
public:
	//! Constructor.
	PassThroughFilter(double, double, double, double, double, double);

	//! FilterFunction.
	void filter(PointCloud&);
private:
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;
};
#endif  // !PassThroughFilter_h



