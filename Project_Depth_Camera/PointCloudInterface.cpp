#include "PointCloudInterface.h"

/*
 * @file	PointCloudInterface.cpp
 * @Author	Bilal Demir (152120191036@ogrenci.ogu.edu.tr)
 * @date	January, 2022
 */

Interface::~Interface()
{
	for (auto it : generators)
	{
		it = nullptr;
		delete it;
	}
	generators.clear();
	recorder = NULL;
	delete recorder;
}

bool Interface::generate()
{
	for (auto it : generators)
		pointcloud = pointcloud + it->captureFor();
	return !pointcloud.isEmpty();
}
bool Interface::record()
{
	return recorder->save(pointcloud);
}