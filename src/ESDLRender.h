#include <SDL/SDL.h>

#ifndef ESDLRENDER
#define ESDLRENDER
class ESDLRender {
	protected:
	  unsigned int m_Keys[SDLK_LAST];
	public:
		ESDLRender(int x, int y);
		~ESDLRender();

		SDL_Surface *sdlSurface;
		virtual bool run();
		virtual void draw();
		virtual void resize(int x, int y);
		virtual bool processEvents();
};
#endif
