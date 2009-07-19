#include "ObjIns.h"

ObjIns::ObjIns() {

}

void ObjIns::print() {
	std::cout<<"ObjIns name "<<*this->name<<" associatedObj "<<*this->associatedObj<<std::endl;
	std::cout<<"Location "<<this->loc->toString()<< " Rotation "<<this->rot->toString()<<std::endl;
}