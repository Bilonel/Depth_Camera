/**
* @file PointCloudFilter.h
* @Author Hakam Chedo (152120181096)
* @date 10 Jan 2022
* @brief It will be collected under the abstract class. The filter member function will be a pure virtual function.
*
* Detailed description of file.
*/
#pragma once
#ifndef PointCloudFilter_h
#define PointCloudFilter_h
#include "Transform.h"
//! PointCloudFilter Class.
/*!
It will be collected under the abstract class. The filter member function will be a pure virtual function.
*/
class PointCloudFilter
{
public:
	//! Constructor. 
	PointCloudFilter();
	//! Destructor.
	~PointCloudFilter();
	//! Pure virtual function
	virtual void filter(PointCloud&) = 0;
};
#endif // !PointCloudFilter_h
