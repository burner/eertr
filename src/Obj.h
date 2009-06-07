#include "Vec3f.h"
#include "Tri.h"
#include <vector>
#include <string>
#ifndef OBJ
#define OBJ
class Obj {
	private:
		std::vector<Vec3f*> *vertices;
		std::vector<Vec3f*> *normals;
		std::vector<Tri*> *triangle;

	public:
		Obj(std::string filename);
		~Obj();
		void render();
};
#endif
