#include "PassThroughFilter.h"

/**
* @param xmin, xmax, ymin, ymax, zmin, zmax an double argument to store in
* -lowerLimitX: double
* -upperLimitX: double
* -lowerLimitY: double
* -upperLimitY: double
* -lowerLimitZ: double
* -upperLimitZ: double
*/
PassThroughFilter::PassThroughFilter(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
	:lowerLimitX(xmin), upperLimitX(xmax), lowerLimitY(ymin), upperLimitY(ymax), lowerLimitZ(zmin), upperLimitZ(zmax) {}

/**
* Delete points that is not in lower upper limit x,y,z
*
*
* @param pc PointCloud Class object that need to call getpointNumber(), getpoint(int), deletepoint(int) functions.
*/
void PassThroughFilter::filter(PointCloud& pc)
{
	for (int i = 0; i < pc.get_pointNumber(); i++)
	{
		if ((pc.get_point(i).get_X() < lowerLimitX || pc.get_point(i).get_X() > upperLimitX) || (pc.get_point(i).get_Y() < lowerLimitY || pc.get_point(i).get_Y() > upperLimitY) || (pc.get_point(i).get_Z() < lowerLimitZ || pc.get_point(i).get_Z() > upperLimitZ))
		{
			pc.deletepoint(i);
			i -= 1;
		}
	}
}