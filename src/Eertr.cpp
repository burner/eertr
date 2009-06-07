#include "Eertr.h"
Eertr::Eertr(int height, int width) {
	events = true;
	Timer::createTimer("fpsTicks");
	Timer::createTimer("proEvents");
	Timer::createTimer("draw");
	Timer::createTimer("drawTw");
	Timer::createTimer("swapBuf");
	
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
	TwAddVarRO(infoBar, "FPS", TW_TYPE_INT32, &fps,
			" label='FPS' help='Frames per second' ");
	TwAddVarRO(infoBar, "TimeProcessEvents", TW_TYPE_INT32, &timeProcessEvents,
		" label='EventProcessTime' help='time to process events in ms' ");
	TwAddVarRO(infoBar, "TWDrawTime", TW_TYPE_INT32, &timeTwDraw,
		" label='TWDrawTime' help='time to draw TW' ");
	TwAddVarRO(infoBar, "DrawTime", TW_TYPE_INT32, &timeDraw,
		" label='DrawTime' help='time to draw' ");
	TwAddVarRO(infoBar, "SwapBuffer", TW_TYPE_INT32, &timeSwapBuffer,
		" label='SwapBufferTime' help='time to swap buffer' ");
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
	while(events) {
		Timer::reset("proEvents");
		events = processEvents();
		timeProcessEvents = Timer::read("proEvents");
		//calculate FPS
		if(Timer::read("fpsTicks") >= 1000) {
			Timer::reset("fpsTicks");
			fps = frames;
			frames = 0;
		} else {
			frames++;
		}
		
		Timer::reset("draw");
		draw();
		timeDraw = Timer::read("draw");
		Timer::reset("drawTw");
		TwDraw();
		timeTwDraw = Timer::read("drawTw");
		Timer::reset("swapBuf");
		SDL_GL_SwapBuffers();
		timeSwapBuffer = Timer::read("swapBuf");
	}
}