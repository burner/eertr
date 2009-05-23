#include "GraphNode.h"
#include "Vec3f.h"
#include "Obj.h"
#include <vector>

GraphNode::GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, Obj *mesh) {
	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
	this->mesh = mesh;
}
