#include <string>
#include "Obj.h"
#include "Vec3f.h"

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
};
#endif