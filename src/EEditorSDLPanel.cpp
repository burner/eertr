#include <wx/wx.h>
#include <SDL/SDL.h>
#include <wx/dcbuffer.h>
#include <wx/image.h>
#include "EEditorFrame.h"
#include "EEditorSDLPanel.h"

inline void EEditorSDLPanel::onEraseBackground(wxEraseEvent &) {
  
}

IMPLEMENT_CLASS(EEditorSDLPanel, wxPanel)
BEGIN_EVENT_TABLE(EEditorSDLPanel, wxPanel)
  EVT_PAINT(EEditorSDLPanel::onPaint)
  EVT_ERASE_BACKGROUND(EEditorSDLPanel::onEraseBackground)
  EVT_IDLE(EEditorSDLPanel::onIdle)
END_EVENT_TABLE()

EEditorSDLPanel::EEditorSDLPanel(wxWindow *parent) : wxPanel(parent, IDP_PANEL), screen(0) {
  wxSize size(800,480);
  SetMinSize(size);
  SetMaxSize(size);
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
  wxBitmap bmp(wxImage(screen->w, screen->h, static_cast<unsigned char *>(screen->pixels), true));

  // unlock the screen
  if (SDL_MUSTLOCK(screen)) {
	SDL_UnlockSurface(screen);
  }

  // paint the screen
  wxBufferedPaintDC dc(this, bmp);
}
void EEditorSDLPanel::onIdle(wxIdleEvent &) {
    // create the SDL_Surface
    createScreen();

    // Lock surface if needed
    if (SDL_MUSTLOCK(screen)) {
        if (SDL_LockSurface(screen) < 0) {
            return;
        }
    }

    // Ask SDL for the time in milliseconds
    int tick = SDL_GetTicks();

    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 800; x++) {
            wxUint32 color = (y * y) + (x * x) + tick;
            wxUint8 *pixels = static_cast<wxUint8 *>(screen->pixels) +
                              (y * screen->pitch) +
                              (x * screen->format->BytesPerPixel);

            #if SDL_BYTEORDER == SDL_BIG_ENDIAN
                pixels[0] = color & 0xFF;
                pixels[1] = (color >> 8) & 0xFF;
                pixels[2] = (color >> 16) & 0xFF;
            #else
                pixels[0] = (color >> 16) & 0xFF;
                pixels[1] = (color >> 8) & 0xFF;
                pixels[2] = color & 0xFF;
            #endif
        }
    }

    // Unlock if needed
    if (SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }

    // refresh the panel
    Refresh(false);

    // throttle to keep from flooding the event queue
    wxMilliSleep(33);
}

void EEditorSDLPanel::createScreen() {
    if (!screen) {
        int width, height;
        GetSize(&width, &height);

        screen = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height,
                                      24, 0, 0, 0, 0);
    }
}
