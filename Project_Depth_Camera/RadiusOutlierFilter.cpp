#include "RadiusOutlierFilter.h"

/**
* @param r an double argument to store in radius:double.
*/
RadiusOutlierFilter::RadiusOutlierFilter(double r) : radius(r) {}

/**
* If there is no other point closer to the point than the radius value, that point is subtracted from the point cloud.
*
*
* @param pc PointCloud Class object that need to call getpointNumber(), deletepoint(int) functions.
*/
void RadiusOutlierFilter::filter(PointCloud& pc)
{
	int flag = 0;
	for (int i = 0; i < pc.get_pointNumber(); i++)
	{
		flag = 0;
		for (int j = 0; j < pc.get_pointNumber(); j++)
		{
			if (j != i) {
				if (pc.get_point(i).distance(pc.get_point(j)) < radius) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			pc.deletepoint(i);
			i -= 1;
		}
	}
}