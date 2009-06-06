#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <string>

#ifndef EERTRWINDOW
#define EERTRWINDOW
class EertrWindow {
	private:
		int width;
		int height;
		int bpp;
		bool fullscreen;
		std::string title;

	public:
		EertrWindow();
		~EertrWindow();
		
		bool createWindow(int width, int height, int bpp, bool fullscreen);
		void setSize(int width, int height);
		int getHeight();
		int getWidth();
};
#endif