#include "Camera.h"
#include <SDL/SDL_opengl.h>
Camera::Camera() {

}

void Camera::placeCam() {
	glRotatef(pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(heading, 0.0f, 1.0f, 0.0f);
	glTranslatef(-pos.x, -pos.y, -pos.z);
}