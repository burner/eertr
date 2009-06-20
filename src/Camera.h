#include "prim/Vec3f.h"
#ifndef CAMERA
#define CAMERA
class Camera {
	private:
	
	public:
		Vec3f pos;
		float pitch;
		float heading;
		
		Camera();
		void placeCam();
};
#endif