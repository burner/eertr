#include "Vec3f.h"
#include <string>
#ifndef TRI
#define TRI
class Tri {
	public:
		Tri(Vec3f *v1, Vec3f *v2, Vec3f *v3);
		std::string toString();
		Vec3f *v1;
		Vec3f *v2;
		Vec3f *v3;
};
#endif
