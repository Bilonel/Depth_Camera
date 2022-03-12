#pragma once
#ifndef Transform_h
#define Transform_h

#include "PointCloudRecorder.h"
#include <Eigen/Dense>

#define dimensions 3
/*
 * @file	Transform.h
 * @Author	Bilal Demir (152120191036@ogrenci.ogu.edu.tr)
 * @date	December, 2021
 */

class Transform
{
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
	void setTransMatrix();
	Point doTransform(Point p);
public:
	Transform(Eigen::Vector3d ang, Eigen::Vector3d tr);
	~Transform();
	void setRotation(double ang[]);
	void setRotation(Eigen::Vector3d ang) { this->angles = ang; }
	void setTranslation(double tr[]);
	void setTranslation(Eigen::Vector3d tr) { this->trans = tr; }
	PointCloud doTransform(PointCloud pc);
};
#endif