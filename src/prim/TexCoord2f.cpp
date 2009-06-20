#include "TexCoord2f.h"

TexCoord2f::TexCoord2f() {
	this->u = 0.0;
	this->v = 0.0;
}

TexCoord2f::TexCoord2f(float u, float v) {
	this->u = u;
	this->v = v;
}

TexCoord2f::TexCoord2f(TexCoord2f *toCopy) {
	this->u = toCopy->u;
	this->v = toCopy->v;
}