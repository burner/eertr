#include "ObjLoader.h"
#include "Vec3f.h"
#include <vector>
#include <iostream>

using namespace std;
int main(void) {
	ObjLoader *file = new ObjLoader("t270u.obj");
	vector<Vec3f*>* foo = file->getVectors();
	vector<Vec3f*>* args = file->getNormals();
	vector<Tri*>* args2 = file->getTriangle();

	for(int i = 0; i < foo->size(); i++) {
		cout<<(*foo)[i]->toString()<<endl;
	}
	cout<<"\n"<<endl;
	for(int i = 0; i < args->size(); i++) {
		cout<<(*args)[i]->toString()<<endl;
	}
	for(int i = 0; i < args2->size(); i++) {
		cout<<(*args2)[i]->toString()<<endl;
	}
	return 1;
}
