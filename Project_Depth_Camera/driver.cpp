#include "PointCloudInterface.h"

/*
 * @file	driver.cpp
 * @Author	Bilal Demir (152120191036@ogrenci.ogu.edu.tr)
 * @date	January, 2022
 */

int main()
{
	FilterPipe* filter1, *filter2;
	filter1 = filter2= new FilterPipe();
	filter1->addFilter(new RadiusOutlierFilter(25));
	filter1->addFilter(new PassThroughFilter(0, 400, 0, 400, -45, 45));
	filter2->addFilter(new RadiusOutlierFilter(25));
	filter2->addFilter(new PassThroughFilter(0, 500, 0, 500, -45, 45));
	
	Interface interface;
	interface.addGenerator(new PointCloudGenerator("camera1.txt", Transform({ 0.0, 0.0, -M_PI / 2.0 }, { 100.0, 500.0, 50.0 }), filter1));
	interface.addGenerator(new PointCloudGenerator("camera2.txt", Transform({ 0.0, 0.0, M_PI / 2.0 }, { 550.0, 150.0, 50.0 }), filter2));
	interface.setRecorder(new PointCloudRecorder("Res_v2.txt"));
	
	if(interface.generate())
		interface.record();
}