#include "EertrWindow.h"
#include <SDL/SDL.h>
#include <AntTweakBar.h>
#include <iostream>

#ifndef EERTR
#define EERTR
class Eertr {
	private:
	  EertrWindow window;
	  unsigned int keys[SDLK_LAST];
	  
	  void draw();
	  void resize(int x, int y);
	  bool processEvents();

	  TwBar *infoBar;

	public:
		Eertr(int height, int width);
		~Eertr(); 
		void run();
};
#endif