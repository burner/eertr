#include <string>
#ifndef TEXCOORD2F
#define TEXCOORD2F
class TexCoord2f {
	public:
		float u;
		float v;
		/// Empty Constructor everything will be zero
		TexCoord2f();
		/// Constructor taking two floats
		TexCoord2f(float u, float v);
		/// Copy Constructor
		TexCoord2f(TexCoord2f *toCopy);
};
#endif