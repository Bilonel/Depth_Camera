#define _USE_MATH_DEFINES
#include "FilterPipe.h"

class PointCloudGenerator : public DepthCamera {
private:
	Transform transform;
	FilterPipe* filterPipe;
public:
	//PointCloudGenerator();
	PointCloudGenerator(std::string filename,Transform transform,FilterPipe* filterpipe): DepthCamera(filename),transform(transform),filterPipe(filterpipe)
	{}
	~PointCloudGenerator();

	PointCloud capture();
	PointCloud captureFor();
	void setFilterPipe(FilterPipe*);
	//void setTransform(Transform);
};