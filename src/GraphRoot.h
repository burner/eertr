#include "GraphNode.h"

#ifndef GRAPHROOT_H
#define GRAPHROOT_H
class GraphRoot : GraphNode {
	public:
		GraphRoot(Vec3f *position, Vec3f *rotation);
		GraphRoot();
};
#endif