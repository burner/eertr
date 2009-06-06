#include "Eertr.h"
Eertr::Eertr() {
	if(!window.createWindow(1024, 600, 32, false)) {
		return;
	}
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

Eertr::~Eertr(){
}

void Eertr::draw() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void Eertr::resize(int x, int y) {
	std::cout << "Resizing Window to " << x << "x" << y << std::endl;

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
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
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
	return true;
}

void Eertr::run() {
	while(processEvents()) {
		draw();
		SDL_GL_SwapBuffers();
	}
}