#include "EertrWindow.h"
EertrWindow::EertrWindow():
	width(0),
	height(0),
	bpp(0),
	fullscreen(false)
{}

EertrWindow::~EertrWindow() {
	SDL_Quit();
}

bool EertrWindow::createWindow(int width, int height, int bpp, bool fullscreen) {
	if( SDL_Init( SDL_INIT_VIDEO ) != 0)  {
		return false;
	}

	//Copy the values incase we need them
	height = height;
	width = width;
	title = title;
	fullscreen = fullscreen;
	bpp = bpp;

	//all values are "at least"!	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Set the title.
	SDL_WM_SetCaption("EERTR", "EERTR");

	// Flags tell SDL about the type of window we are creating.
	int flags = SDL_OPENGL;

	if(fullscreen == true) {
		flags |= SDL_FULLSCREEN;
	}

	// Create the window
	SDL_Surface * screen = SDL_SetVideoMode( width, height, bpp, flags );
		
	if(screen == 0) {
		return false;
	}

	//SDL doesn't trigger off a ResizeEvent at startup, but as we need this for OpenGL, we do this ourself
	SDL_Event resizeEvent;
	resizeEvent.type = SDL_VIDEORESIZE;
	resizeEvent.resize.w = width;
	resizeEvent.resize.h = height;
	
	SDL_PushEvent(&resizeEvent);
	return true;
}
	
void EertrWindow::setSize(int width, int height) {
	height = height;
	width = width;
}
