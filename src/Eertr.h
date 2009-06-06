#include "EertrWindow.h"
#include <SDL/SDL.h>
#include <iostream>

#ifndef EERTR
#define EERTR
class Eertr {
	protected:
	  EertrWindow window;
	  unsigned int keys[SDLK_LAST];
	  
	  void draw();
	  void resize(int x, int y);
	  bool processEvents();

	public:
		Eertr();
		~Eertr(); 
		void run();
};
#endif