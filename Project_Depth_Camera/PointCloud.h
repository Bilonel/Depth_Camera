#include "Point.h"

/**
* @file	PointCloud.h
* @Author	Hüseyin Kaymak 152120181100 
* @date	Dec, 2021
* @brief   This class is to set all points to point cloud.
* Detailed description of file.
*/

//! PointCloud Class.
 /*!
 This class is to set all points to point cloud.
 */
class PointCloud{
private:
	int num_of_point;
	std::list<Point> points;
public:
	//! Constructor.
	PointCloud(int num_of_point=0);
	//! Destructor.
	~PointCloud();

	//! addPointFunction.
	void addPoint(Point p);
	//! get point Function.
	const Point get_point(int i);
	//! set point number Function.
	void setpointNumber(int num_of_point);
	//! get point number Function.
	int get_pointNumber() const;
	//! operator+ Function.
	PointCloud operator+(PointCloud PC);
	//! operator= Function.
	void operator=(PointCloud* PC);
	//! deletepoint Function.
	void deletepoint(int i);
	bool isEmpty() { return num_of_point == 0; }
};