#include "Vec3f.h"
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

Vec3f::Vec3f() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vec3f::Vec3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3f::Vec3f(Vec3f *old) {
	this->x = old->x;
	this->y = old->y;
	this->z = old->z;
}

Vec3f::~Vec3f() {
}

float Vec3f::getLength() {
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vec3f::normalize() {
	float f = 1.0 / this->getLength();
	this->mult(f);
}

void Vec3f::add(Vec3f *vec) {
	this->x += vec->x;
	this->y += vec->y;
	this->z += vec->z;
}

Vec3f* Vec3f::addR(Vec3f *vec) {
	this->x += vec->x;
	this->y += vec->y;
	this->z += vec->z;
	return this;
}

void Vec3f::sub(Vec3f *vec) {
	this->x -= vec->x;
	this->y -= vec->y;
	this->z -= vec->z;
}

Vec3f* Vec3f::subR(Vec3f *vec) {
	return new Vec3f(this->x - vec->x, this->y - vec->y, this->z - vec->z);
}

void Vec3f::mult(float scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

void Vec3f::div(float scalar) {
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
}


Vec3f* Vec3f::getCrossProd(Vec3f *vector) {
	return new Vec3f(
			this->y * vector->z - this->z * vector->y,
			this->z * vector->x - this->x * vector->z,
			this->x * vector->y - this->y * vector->x);
}

void Vec3f::print() {
	std::cout<<"X = "<<this->x<<" Y = "<<this->y<<" Z = "<<this->z<<std::endl;
}

std::string Vec3f::toString() {
	std::ostringstream out;
	out<<"X = "<<this->x<<" Y = "<<this->y<<" Z = "<<this->z;
	return out.str();
}