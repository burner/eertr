#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include "ESDLRender.h"

ESDLRender::ESDLRender(int x, int y) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout<<"Unable to init SDL"<<std::endl;
		exit(0);
	}
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	int flags = SDL_OPENGL;
	sdlSurface = SDL_SetVideoMode(x, y, 32, flags);
	//sdlSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,x,y,24, 0, 0, 0, 0);

	if(sdlSurface == 0) {
		std::cout<<"Unable to setup VideoMode"<<std::endl;
		exit(0);
	}
	SDL_Event resizeEvent;
	resizeEvent.type = SDL_VIDEORESIZE;
	resizeEvent.resize.w = x;
	resizeEvent.resize.h = y;
		
	SDL_PushEvent(&resizeEvent);
}	

ESDLRender::~ESDLRender() {
	SDL_Quit();
}

bool ESDLRender::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {//get all events
		switch (event.type) {
			// Quit event
			case SDL_QUIT: {
				// Return false because we are quitting.
				return false;
			}
			case SDL_KEYDOWN: {
				SDLKey sym = event.key.keysym.sym;
				if(sym == SDLK_ESCAPE) {//Quit if escape was pressed
					return false;
				}
				m_Keys[sym] = 1;
				break;
			}
			case SDL_KEYUP:	{
				SDLKey sym = event.key.keysym.sym;
				m_Keys[sym] = 0;
				break;
			}
			case SDL_VIDEORESIZE: {
			//the window has been resized so we need to set up our viewport and projection according to the new size
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

void ESDLRender::resize(int x, int y) {
	glViewport(0,0,x,y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)x/(GLfloat)y,1.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool ESDLRender::run() {
	while(processEvents())	{
		ESDLRender::draw();
	}
	return true;
}

void ESDLRender::draw() {
	
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClearColor( 0.7f, 0.0f, 0.0f, 0.0f );
    /* Move Left 1.5 Units And Into The Screen 6.0 */
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -6.0f );

    glBegin( GL_TRIANGLES );             /* Drawing Using Triangles       */
      glColor3f(   1.0f,  0.0f,  0.0f ); /* Red                           */
      glVertex3f(  0.0f,  1.0f,  0.0f ); /* Top Of Triangle               */
      glColor3f(   0.0f,  1.0f,  0.0f ); /* Green                         */
      glVertex3f( -1.0f, -1.0f,  0.0f ); /* Left Of Triangle              */
      glColor3f(   0.0f,  0.0f,  1.0f ); /* Blue                          */
      glVertex3f(  1.0f, -1.0f,  0.0f ); /* Right Of Triangle             */
    glEnd( );       
    SDL_GL_SwapBuffers( );	  
}
