/**
* @file RadiusOutlierFilter.h
* @Author Hakam Chedo (152120181096)
* @date 15 Dec 2021
* @brief This class is filter some points that If there is no other point closer to the point than the radius value, that point is subtracted from the point cloud.
*
* Detailed description of file.
*/
#pragma once
#ifndef RadiusOutlierFilter_h
#define RadiusOutlierFilter_h
#include "PassThroughFilter.h"
//! RadiusOutlierFilter Class.
/*!
This class is filter some points that If there is no other point closer to the point than the radius value, that point is subtracted from the point cloud.
*/
class RadiusOutlierFilter : public PointCloudFilter
{
public:
	//! Constructor.
	RadiusOutlierFilter(double);
	//! FilterFunction.
	void filter(PointCloud&);

private:
	double radius;
};

#endif // !RadiusOutlierFilter_h
