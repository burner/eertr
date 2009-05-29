#include <glib.h>
#include <gtkmm.h>
#include <gtkmm/socket.h>
#include <SDL/SDL.h>
#include "EEditor.h"
#include "ESDLRender.h"

EEditor::EEditor(int argc, char ** argv) {
	main = new Gtk::Main(argc, argv);
	socketWidth = 1280;
	socketHeight = 720;
	window = new Gtk::Window();
	window->set_title("EERTR EDITOR");
	sdlSocket = new Gtk::Socket();
	sdlSocket->set_size_request(socketWidth, socketHeight);
	window->set_border_width(6);
}

EEditor::~EEditor() {
	if(sdlSurface) 
		SDL_FreeSurface(sdlSurface);
}

void EEditor::initialize() {
	sdlBox = new Gtk::VBox();
	sdlBox->pack_start(*sdlSocket, false, false);
	window->add(*sdlBox);
	
	std::stringstream sdlhack;
	sdlhack<<"SDL_WINDOWID=" <<sdlSocket->get_id() << std::ends;
	char* winhack=new char[32];
	sprintf(winhack,sdlhack.str().c_str());
	SDL_putenv(winhack);

	render = new ESDLRender(socketWidth, socketHeight);

	Glib::signal_timeout().connect(sigc::mem_fun(*render, &ESDLRender::run), 5);

	main->run(*window);
}

