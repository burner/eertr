#include "ESDLEditorRender.h"
#include "ESDLRender.h"

ESDLEditorRender::ESDLEditorRender(int x, int y) : ESDLRender(x,y) { };

bool ESDLEditorRender::run() {
	ESDLRender::draw();
	SDL_GL_SwapBuffers();

	return false;
}