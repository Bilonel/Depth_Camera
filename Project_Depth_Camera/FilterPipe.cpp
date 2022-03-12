#include "FilterPipe.h"

FilterPipe::FilterPipe() {}
FilterPipe::~FilterPipe() 
{
	for (auto it : filter)
	{
		it = nullptr;
		delete it;
	}
	filter.clear();
}

/**
* @param filter an PointCloudFilter class object that will store to this calss
*/
void FilterPipe::addFilter(PointCloudFilter* filter) {
	this->filter.push_back(filter);
}
/**
* @param pc an PointCloud class object that will be filtered.
*/
void FilterPipe::filterOut(PointCloud& pc) {
	for (int i = 0; i < this->filter.size(); i++)
		this->filter[i]->filter(pc);	
}