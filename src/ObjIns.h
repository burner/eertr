#include <string>
#include "Obj.h"
#include "Vec3f.h"

#ifndef OBJINS
#define OBJINS
class ObjIns {
	private:
		unsigned id;
		std::string name;
		Obj associatedObj;
	public:
		Vec3f loc;
		Vec3f rot;
		
		ObjIns();
		void draw();
};
#endif