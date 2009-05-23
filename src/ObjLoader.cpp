#include "ObjLoader.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Vec3f.h"

using namespace std;
ObjLoader::ObjLoader(string filename) {
	vectors = new vector<Vec3f*>();
	triangle = new vector<Tri*>();
	normals = new vector<Vec3f*>();
	
	//open file
	ifstream ifs(filename.c_str());
	string temp;
	while(getline(ifs, temp)) {
		//debug
		//cout<<temp<<endl;
		parseStr(temp);
	}
}

void ObjLoader::parseStr(string line) {
	if (line.at(0) == 'v') {
		if (line.at(1) == ' ') {
			readVertexLine(line);
		}
		if (line.at(1) == 'n') {
			readVertexNormalLine(line);
		}
		if (line.at(1) == 't') {
			readVertexTexCoordLine(line);
		}
	}else if (line.at(0) == 'f') {
		readFaceLine(line);
	}
}

void ObjLoader::readVertexLine(string line) {
	string tmp[3];
	int j = 0;
	for(unsigned i = 2; i < line.length() && j < 3; i++) {
		if(line.at(i) == ' ') {
			j++;
			continue;
		}
		tmp[j].push_back(line.at(i));
	}
	vectors->push_back(new Vec3f(
		(float)atof(tmp[0].c_str()),
		(float)atof(tmp[1].c_str()),
		(float)atof(tmp[2].c_str())));

}
void ObjLoader::readVertexNormalLine(string line) {
	string tmp[3];
	unsigned j = 0;
	for(unsigned i = 3; i < line.length() && j < 3; i++) {
		if(line.at(i) == ' ') {
			j++;
			continue;
		}
		tmp[j].push_back(line.at(i));
	}
	normals->push_back(new Vec3f(
		(float)atof(tmp[0].c_str()),
		(float)atof(tmp[1].c_str()),
		(float)atof(tmp[2].c_str())));

	return;
}
void ObjLoader::readVertexTexCoordLine(string line) {
	string tmp[3];
	unsigned j = 0;
	for(unsigned i = 3; i < line.length() && j < 3; i++) {
		if(line.at(i) == ' ') {
			j++;
			continue;
		}
		tmp[j].push_back(line.at(i));
	}
	normals->push_back(new Vec3f(
		(float)atof(tmp[0].c_str()),
		(float)atof(tmp[1].c_str()),
		(float)atof(tmp[2].c_str())));

	return;
}
void ObjLoader::readFaceLine(string line) {
	string tmp[9];
	unsigned j = 0;
	for(unsigned i = 2; i < line.length() && j < 9; i++) {
		//if blank set pointer to next array entry and continue
		if(line.at(i) == ' ') {
			j++;
			continue;
		}
		//if / set pointer to next array entry and continue
		if(line.at(i) == '/') {
			j++;
			continue;
		}
		tmp[j].push_back(line.at(i));
	}
	return;
}

vector<Vec3f*>* ObjLoader::getVectors() {
	return vectors;
}

vector<Tri*>* ObjLoader::getTriangle() {
	return triangle;
}

vector<Vec3f*>* ObjLoader::getNormals() {
	return normals;
}
