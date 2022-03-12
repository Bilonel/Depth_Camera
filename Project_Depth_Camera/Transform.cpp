#include "Transform.h"

/*
 * @file	Transform.cpp
 * @Author	Bilal Demir (152120191036@ogrenci.ogu.edu.tr)
 * @date	December, 2021
 */

Transform::~Transform()
{
}

void Transform::setTransMatrix()
{
	transMatrix <<
		/* ROW 0 */
		/*[0]*/	cos(angles[2]) * cos(angles[1]),
		/*[1]*/	cos(angles[2])* sin(angles[1])* sin(angles[0]) - sin(angles[2]) * cos(angles[0]),
		/*[2]*/	cos(angles[2])* sin(angles[1])* cos(angles[0]) + sin(angles[2]) * sin(angles[0]),		
		/*[3]*/	trans[0]
		,
		/* ROW 1 */
		/*[0]*/	sin(angles[2])* cos(angles[1]),
		/*[1]*/	sin(angles[2])* sin(angles[1])* sin(angles[0]) + cos(angles[2]) * cos(angles[0]),
		/*[2]*/	sin(angles[2])* sin(angles[1])* cos(angles[0]) - cos(angles[2]) * sin(angles[0]),
		/*[3]*/	trans[1]
		,
		/* ROW 2 */
		/*[0]*/	-sin(angles[1]),
		/*[1]*/	cos(angles[1])* sin(angles[0]),
		/*[2]*/	cos(angles[1])* cos(angles[0]),
		/*[3]*/	trans[2]
		,
		// ROW 3
		0, 0, 0, 1 ;
}

Transform::Transform(Eigen::Vector3d ang, Eigen::Vector3d tr)
{
	setRotation(ang);
	setTranslation(tr);
}

void Transform::setRotation(double angles[])
{
	for (int i = 0; i < dimensions; i++)
		this->angles[i] = angles[i];
}

void Transform::setTranslation(double trans[])
{
	for (int i = 0; i < dimensions; i++)
		this->trans[i] = trans[i];
}

PointCloud Transform::doTransform(PointCloud pc)
{
	setTransMatrix();
	PointCloud res(pc.get_pointNumber());
	for (int index = 0; index < pc.get_pointNumber(); index++)
		res.addPoint(doTransform(pc.get_point(index)));
	return res;
}

Point Transform::doTransform(Point p)
{
	Eigen::Vector4d p_point(p.get_X(), p.get_Y(), p.get_Z(), 1);
	Eigen::Vector4d point = transMatrix * p_point;
	return Point(point(0), point(1), point(2));
}
