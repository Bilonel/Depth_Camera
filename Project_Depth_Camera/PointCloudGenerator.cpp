#include "PointCloudGenerator.h"


PointCloudGenerator::~PointCloudGenerator(){
	delete filterPipe;
}

void PointCloudGenerator::setFilterPipe(FilterPipe* filterpipe){
	filterPipe = filterpipe;
}

PointCloud PointCloudGenerator::capture() {
	PointCloud res;
	std::ifstream input_file(filename);
	if (!input_file.is_open())
		std::cout << "File Could not Open !";
	else
	{
		int coordinateX, coordinateY, coordinateZ, numberPoints = 0;
		while (!input_file.eof()) {
			input_file >> coordinateX;
			input_file >> coordinateY;
			input_file >> coordinateZ;
			numberPoints++;

			res.addPoint(Point(coordinateX, coordinateY, coordinateZ));
		}
		res.setpointNumber(numberPoints);
	}
	input_file.close();
	return res;
}

PointCloud PointCloudGenerator::captureFor() {

	PointCloud res=capture();

	filterPipe->filterOut(res);
	res = transform.doTransform(res);
	
	return res;
}