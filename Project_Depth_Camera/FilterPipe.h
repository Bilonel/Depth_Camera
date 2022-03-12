/**
* @file FilterPipe.h
* @Author Hakam Chedo (152120181096)
* @date 10 Jan 2022
* @brief It is the class that will filter the point cloud that needs to pass through more than one filter.
*
* Detailed description of file.
*/
#pragma once
#ifndef FilterPipe_h
#define FilterPipe_h
#include "RadiusOutlierFilter.h"
//! FilterPipe Class.
/*!
It is the class that will filter the point cloud that needs to pass through more than one filter.
*/
class FilterPipe
{
public:
	//! Constructor.
	FilterPipe();
	//! Destructor.
	~FilterPipe();
	//! Add filter Function.
	void addFilter(PointCloudFilter*);
	//! Filter out Function.
	void filterOut(PointCloud&);

private:
	std::vector<PointCloudFilter*> filter;
};
#endif // !FilterPipe_h
