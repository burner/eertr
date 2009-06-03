#include "ESDLEditorRender.h"
#include "ESDLRender.h"

ESDLEditorRender::ESDLEditorRender(int x, int y) : ESDLRender(x,y) {
  return;
};

bool ESDLEditorRender::run() {
    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	ESDLRender::draw();
	return true;
}