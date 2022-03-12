#include "PointCloud.h"


/**
 * @file	DepthCamera.h
 * @Author	Hüseyin Kaymak / 152120181100@ogrenci.ogu.edu.tr
 * @date	January, 2022
 * @brief   This class is to read txt file and store point coordinate to point.
 * Detailed description of file.
 */

 //! DepthCamera Class.
 /*!
 This class is to read txt file and store point coordinate to point.
 */
class DepthCamera
{
protected:
	std::string filename;
public:
	//! Constructor.
	/**
	* @param filename an string argument to set file name.
	*/
	DepthCamera(std::string filename) :filename(filename) {}
	//! set file name function.
	void set_filename(std::string filename) { this->filename = filename; }
	//! capture function.
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};

