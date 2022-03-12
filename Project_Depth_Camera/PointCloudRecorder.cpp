#include "PointCloudRecorder.h"

/*
 * @file	PointCloudRecorder.cpp
 * @Author	Bilal Demir / 152120191036@ogrenci.ogu.edu.tr
 * @date	January, 2022
 */

 /**
  * @param pc an PointCloud Class object.
  * @return when value of i is greater than or equal to number of points.
  */
bool PointCloudRecorder::save(PointCloud pc)
{
	int i = 0;
	std::ofstream outfile(filename);
	if (!outfile.is_open())
		std::cout<<"Out File Could not Open !\n";
	else
		for (; i < pc.get_pointNumber(); i++)
			outfile << pc.get_point(i).get_X() << " "
				<< pc.get_point(i).get_Y() << " "
				<< pc.get_point(i).get_Z() << std::endl;
	return i >= pc.get_pointNumber();
}