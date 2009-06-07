#include "Obj.h"
#include "ObjLoader.h"

Obj::Obj(std::string filename) {
	ObjLoader loader(filename);
	this->vertices = loader.getVertices();
	this->triangle = loader.getTriangle();
	this->normals = loader.getNormals();
}