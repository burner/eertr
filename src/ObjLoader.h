#include "Vec3f.h"
#include "Tri.h"
#include <vector>
#include <string>
#ifndef OBJLOADER
#define OBJLOADER
class ObjLoader {
	private:
		std::vector<Vec3f*> *vectors;
		std::vector<Tri*> *triangle;
		std::vector<Vec3f*> *normals;
		
		void parseStr(std::string line);
		void readVertexLine(std::string line);
		void readVertexNormalLine(std::string line);
		void readVertexTexCoordLine(std::string line);
		void readFaceLine(std::string line);

	public:
		ObjLoader(std::string filename);
		std::vector<Vec3f*>* getVertices();
		std::vector<Tri*>* getTriangle();
		std::vector<Vec3f*>* getNormals();
};
#endif
