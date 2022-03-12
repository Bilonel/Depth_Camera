#include "Point.h"

using namespace std;


Point::~Point(){
}

/**
*@param x an double argument to set x.
*/
void Point::set_X(double x) {Point::x = x;}	//or this->x = x;
/**
*@param y an double argument to set y.
*/
void Point::set_Y(double y) {Point::y = y;} //or this->y = y;
/**
*@param z an double argument to set z.
*/
void Point::set_Z(double z) {Point::z = z;}	//or this->z = z;

/**
*@return x value.
*/
double Point::get_X()const {return x;}
/**
*@return y value.
*/
double Point::get_Y()const {return y;}
/**
*@return z value.
*/
double Point::get_Z()const {return z;}


/**
* @param p an Point class object that need to check with if the point is equal.
* @return boolean.
*/
bool Point::operator==(Point& P)  {
	if (this->x == P.x && this->y == P.y && this->z == P.z)
		return true;
	return false;
}
/**
* @param p an Point class object that need to find distance with.
* @return the distance of two points.
*/
double Point::distance(const Point& P) const {
	double distance_of_two_points;
	distance_of_two_points = sqrt(pow(P.x - x, 2) + pow(P.y - y, 2) + pow(P.z - z, 2));
	return distance_of_two_points;
}