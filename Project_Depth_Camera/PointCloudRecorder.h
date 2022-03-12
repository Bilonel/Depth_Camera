#pragma once
#include "DepthCamera.h"

/**
 * @file	PointCloudRecorder.h
 * @Author	Bilal Demir / 152120191036@ogrenci.ogu.edu.tr
 * @date	January, 2022
 * @brief   This class is to save all operation to txt file.
 * Detailed description of file.
 */

//! PointCloudRecorder Class.
 /*!
 This class is to save all operation to txt file.
 */
class PointCloudRecorder
{
private:
	std::string filename;
public:
	//! Constructor.
	/**
	* @param _filename an string argument to set resrult file name.
	*/
	PointCloudRecorder(std::string _filename):filename(_filename) {}
	//! saveFunction.
	bool save(PointCloud pc);
};

