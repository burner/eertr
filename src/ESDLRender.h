#include <SDL/SDL.h>

#ifndef ESDLRENDER
#define ESDLRENDER
class ESDLRender {
	public:
		ESDLRender(int x, int y);
		~ESDLRender();

		SDL_Surface *sdlSurface;
		virtual void run();
		virtual void draw();
		virtual void resize(int x, int y);
		virtual bool processEvents();
};
#endif
