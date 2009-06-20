#include "Tri.h"
#include "Vec3f.h"
#include <string>
#include <iostream>
#include <sstream>
Tri::Tri(Vec3f *v1, Vec3f *v2, Vec3f *v3) {
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
}

std::string Tri::toString() {
	std::ostringstream out;
	out<<"V1 = "<<this->v1->toString()<<" V2 = "<<this->v2->toString()<<" V3 = "<<this->v3->toString();
	return out.str();
}
