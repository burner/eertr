#include <wx/wx.h>
#include <wx/wxprec.h>
#include <SDL/SDL.h>
#include <wx/dcbuffer.h>
#include <wx/image.h>
#include <iostream>
#include "EEditorFrame.h"
#include "EEditorSDLPanel.h"
#include "ESDLEditorRender.h"

inline void EEditorSDLPanel::onEraseBackground(wxEraseEvent &) {
  
}

IMPLEMENT_CLASS(EEditorSDLPanel, wxPanel)
BEGIN_EVENT_TABLE(EEditorSDLPanel, wxPanel)
END_EVENT_TABLE()

EEditorSDLPanel::EEditorSDLPanel(wxWindow *parent) : wxPanel(parent, IDP_PANEL), screen(0) {
  Connect(wxEVT_PAINT, wxPaintEventHandler(EEditorSDLPanel::onPaint));
  Connect(wxEVT_IDLE, wxIdleEventHandler(EEditorSDLPanel::onIdle));
  Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(EEditorSDLPanel::onEraseBackground));
  wxSize size(800,480);
  SetMinSize(size);
  SetMaxSize(size);
  edRender = new ESDLEditorRender(800,480);
  screen = edRender->sdlSurface;
}

EEditorSDLPanel::~EEditorSDLPanel() {
  if(screen) {
	SDL_FreeSurface(screen);
  }
}

void EEditorSDLPanel::onPaint(wxPaintEvent &) { 
  if(!screen) {
	return;
  }

  if(SDL_MUSTLOCK(screen)) {
	if(SDL_LockSurface(screen) < 0) {
	  return;
	}
  }
  // create a bitmap from our pixel data
  wxBitmap bmp(wxImage(screen->w, screen->h,
	      static_cast<unsigned char *>(screen->pixels), true));


  // unlock the screen
  if (SDL_MUSTLOCK(screen)) {
	SDL_UnlockSurface(screen);
  }
  
  
  // paint the screen
  wxBufferedPaintDC dc(this, bmp);
}
void EEditorSDLPanel::onIdle(wxIdleEvent &) {
  edRender->run();
  // refresh the panel
  Refresh(false);
  // throttle to keep from flooding the event queue
  wxMilliSleep(33);
}

void EEditorSDLPanel::createScreen() {
    if (!screen) {
        int width, height;
        GetSize(&width, &height);
        screen = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height,24, 0, 0, 0, 0);
    }
}
