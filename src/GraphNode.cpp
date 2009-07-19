#include "GraphNode.h"
#include <vector>

GraphNode::GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation, ObjIns *mesh) {
	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
	this->mesh = mesh;
}

GraphNode::GraphNode(GraphNode *parent, Vec3f *position, Vec3f *rotation) {
	this->parent = parent;
	this->position = position;
	this->rotation = rotation;
}

GraphNode::GraphNode() {
}

void GraphNode::insertChild(GraphNode *child) {
	childs.push_back(child);
}

void GraphNode::insertObjIns(ObjIns *obj) {
	objects.push_back(obj);
}

void GraphNode::print() {
	std::cout<<"GraphNode at "<<this->position->toString()
		<< " rotation at "<<this->rotation->toString()<<std::endl;

	std::cout<<"Obj assigned to this Node"<<std::endl;
	for(unsigned i = 0; i < objects.size(); i++) {
		objects[i]->print();
	}

	std::cout<<"GraphNode assigned to this Node"<<std::endl;
	for(unsigned i = 0; i < childs.size(); i++) {
		childs[i]->print();
	}
}

void GraphNode::render() {
	return;
}