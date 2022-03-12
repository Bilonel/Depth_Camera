#define _USE_MATH_DEFINES
#include <cmath>
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
/**
* @file	Point.h
* @Author	Hüseyin Kaymak 152120181100@ogrenci.ogu.edu.tr
* @date	Dec, 2021
* @brief   This class is to creat point.
* Detailed description of file.
*/

//! Point Class.
 /*!
 This class is to creat point.
 */
class Point{

private:
	double x;
	double y;
	double z;
public:
	//! Constructor.
	/**
	*@param x, y, z an double argument to set x, y, z.
	*/
	Point(double x=0, double y=0, double z=0) :x(x), y(y), z(z) {}
	//! Destructor.
	~Point();
	//! set x function.
	void set_X(double x);
	//! set y function.
	void set_Y(double y);
	//! set z function.
	void set_Z(double z);
	//! get x function.
	double get_X() const;
	//! get y function.
	double get_Y() const;
	//! get z function.
	double get_Z() const;
	//! operator== function.
	bool operator==(Point& P);
	//! distance function.
	double distance(const Point& P) const;
};