#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <string>

#ifndef EERTRWINDOW
#define EERTRWINDOW
class EertrWindow {
	public:
		int width;
		int height;
		int bpp;
		bool fullscreen;
		std::string title;

		EertrWindow();
		~EertrWindow();
		
		bool createWindow(int width, int height, int bpp, bool fullscreen);
		void setSize(int width, int height);

};
#endif