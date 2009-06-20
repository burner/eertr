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

EEditorSDLPanel::EEditorSDLPanel(wxWindow *parent) : wxPanel(parent, IDP_PANEL){
  Connect(wxEVT_PAINT, wxPaintEventHandler(EEditorSDLPanel::onPaint));
  Connect(wxEVT_IDLE, wxIdleEventHandler(EEditorSDLPanel::onIdle));
  Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(EEditorSDLPanel::onEraseBackground));
  wxSize size(800,480);
  SetMinSize(size);
  SetMaxSize(size);
  edRender = new ESDLEditorRender(800,480);
}

EEditorSDLPanel::~EEditorSDLPanel() {
  if(edRender->sdlSurface) {
	SDL_FreeSurface(edRender->sdlSurface);
  }
}

void EEditorSDLPanel::onPaint(wxPaintEvent &) { 
  if(!edRender->sdlSurface) {
	return;
  }

  if(SDL_MUSTLOCK(edRender->sdlSurface)) {
	if(SDL_LockSurface(edRender->sdlSurface) < 0) {
	  return;
	}
  }
  // create a bitmap from our pixel data
  wxBitmap bmp(wxImage(edRender->sdlSurface->w, edRender->sdlSurface->h,
	static_cast<unsigned char *>(edRender->sdlSurface->pixels), true));

  // unlock the screen
  if (SDL_MUSTLOCK(edRender->sdlSurface)) {
	SDL_UnlockSurface(edRender->sdlSurface);
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
