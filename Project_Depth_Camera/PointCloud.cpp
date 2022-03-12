#include "PointCloud.h"
using namespace std;

/**
* @param num_of_point an int argument to set number of point.
*/
PointCloud::PointCloud(int num_of_point){
	this->num_of_point = num_of_point;
}

PointCloud::~PointCloud(){
	points.clear();
}
/**
* @param p an Point class object to add point to point cloud.
*/
void PointCloud::addPoint(Point p) {
	points.push_back(p);
}
/**
* @param i an int argument to get point at position of i.
* @return point at position of i
*/
const Point PointCloud::get_point(int i) {

	list<Point>::iterator it = points.begin();
	advance(it, i);
	return *(it);
}
/**
* @param num_of_point an int argument to set number of point.
*/
void PointCloud::setpointNumber(int num_of_point) {
	this->num_of_point = num_of_point;
}
/**
* @return number of point.
*/
int PointCloud::get_pointNumber()const {
	return num_of_point;
}
/**
* @param pc an PointCloud class object that need to add.
* @return sum of point cloud.
*/
PointCloud PointCloud::operator+(PointCloud PC) {
	
	PointCloud sum(num_of_point+PC.get_pointNumber());
	list<Point>::iterator it;

	for (it = points.begin(); it != points.end(); ++it)
		sum.addPoint(*it);
	for (int i = 0; i < PC.get_pointNumber(); i++)
		sum.addPoint(PC.get_point(i));

	return sum;
}
/**
* @param pc an PointCloud class object that need to copy .
*/
void PointCloud::operator=(PointCloud* PC) {

	setpointNumber(PC->get_pointNumber());
	points = {};

	for (auto it : points) 
		addPoint(it);
}
/**
* @param i an int argument that is index of point that need to delete.
*/
void PointCloud::deletepoint(int point){

	list<Point>::iterator it = points.begin();
	advance(it, point);
	points.erase(it);
	num_of_point--;
}