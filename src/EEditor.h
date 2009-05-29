#include <gtkmm.h>
#include <gtkmm/socket.h>
#include <SDL/SDL.h>
#include "ESDLRender.h"

#ifndef EEDITOR
#define EEDITOR
class EEditor {
	private:
		Gtk::Main *main;
		Gtk::Socket *sdlSocket;
		Gtk::Window *window;
		Gtk::VBox *sdlBox;
		SDL_Surface * sdlSurface;
		ESDLRender *render;
		int socketHeight;
		int socketWidth;

	public:
		EEditor(int argc, char ** argv);
		~EEditor();
		void sdlClear(void); 
		void initialize();
		SDL_Surface* obtSDLSurface();
};
#endif
