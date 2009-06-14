#include "GraphNode.h"
#include <vector>

GraphNode::GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, ObjIns *mesh) {
	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
	this->mesh = mesh;
}
