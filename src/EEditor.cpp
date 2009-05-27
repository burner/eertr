#include <gtkmm.h>
#include <glib.h>
#include <gtkmm/socket.h>
#include <SDL/SDL.h>
#include "ESDLRender.h"
#include "EEditor.h"

EEditor::EEditor(int argc, char ** argv) : main(&argc, &argv), sdlSurface(0) {
	socketWidth = 1280;
	socketHeight = 720;
	window.set_title("EERTR EDITOR");
	sdlSocket.set_size_request(socketWidth, socketHeight);
	window.set_border_width(6);
}

EEditor::~EEditor() {
	if(sdlSurface) 
		SDL_FreeSurface(sdlSurface);
}

void EEditor::initialize() {
	sdlBox.pack_start(sdlSocket, false, false);
	window.add(sdlBox);
	
	std::stringstream sdlhack;
	sdlhack<<"SDL_WINDOWID=" <<sdlSocket.get_id() << std::ends;
	char* winhack=new char[32];
	sprintf(winhack,sdlhack.str().c_str());
	SDL_putenv(winhack);

	render = new ESDLRender(socketWidth, socketHeight);

	Glib::signal_timeout().connect(sigc::mem_fun(render, render::run), 5);

	main.run(window);
}	

