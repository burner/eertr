#include "Eertr.h"
Eertr::Eertr(int height, int width) {
	if(!window.createWindow(width, height, 32, false)) {
		return;
	}
	glClearColor(0.0, 0.0, 0.0, 1.0);
	TwInit(TW_OPENGL, NULL);
	infoBar = TwNewBar("Infobar");
	TwAddVarRO(infoBar, "WindowWidth", TW_TYPE_INT32, &width,
			" label='Window width' help='Width of the graphics window in pixels' ");
	TwAddVarRO(infoBar, "WindowHeight", TW_TYPE_INT32, &height,
			" label='Window height' help='Height of the graphics window in pixels' ");

}

Eertr::~Eertr(){
}

void Eertr::draw() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void Eertr::resize(int x, int y) {
	//std::cout << "Resizing Window to " << x << "x" << y << std::endl;

	if (y <= 0) {
		y = 1;
	}

	glViewport(0,0,x,y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)x/(GLfloat)y,1.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool Eertr::processEvents() {
	int handled;
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		handled = TwEventSDL(&event);
if( !handled )    {
		switch (event.type) {
		// Quit event
			case SDL_QUIT: {
				// Return false because we are quitting.
				return false;
			}

			case SDL_KEYDOWN: {
				SDLKey sym = event.key.keysym.sym;

				if(sym == SDLK_ESCAPE) {
					return false;
				}

				keys[sym] = 1;
					break;
			}

			case SDL_KEYUP: {
				SDLKey sym = event.key.keysym.sym;
				keys[sym] = 0;
				break;
			}

			case SDL_VIDEORESIZE: {
				resize(event.resize.w, event.resize.h);
				break;
			}

			// Default case
			default: {
				break;
			}
		}
	}
}
	return true;
}

void Eertr::run() {
	while(processEvents()) {
		draw();
		TwDraw();
		SDL_GL_SwapBuffers();
	}
}