#pragma once
#ifndef PointCloudInterface_h
#define PointCloudInterface_h

#include "PointCloudGenerator.h"

/*
 * @file	PointCloudInterface.h
 * @Author	Bilal Demir (152120191036@ogrenci.ogu.edu.tr)
 * @date	January, 2022
 */

class Interface
{
private:
	PointCloud pointcloud;
	std::vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
public:
	Interface() { recorder = new PointCloudRecorder("Res_v2.txt"); }
	~Interface();
	void addGenerator(PointCloudGenerator* generator) { generators.push_back(generator); }
	void setRecorder(PointCloudRecorder* rec) { this->recorder = rec; }
	bool generate();
	bool record();
};
#endif