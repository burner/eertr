#include <string>
#include <iostream>
#include "Obj.h"
#include "prim/Vec3f.h"

#ifndef OBJINS
#define OBJINS
class ObjIns {
	public:
		unsigned id;
		std::string *name;
		std::string *associatedObj;
		
		Vec3f *loc;
		Vec3f *rot;
		
		ObjIns();
		void draw();
		void print();
};
#endif