#include <wx/wx.h>
#include <wx/wxprec.h>
#include <SDL/SDL.h>
#include "ESDLEditorRender.h"

#ifndef EEDITORSDLPANEL
#define EEDITORSDLPANEL
class EEditorSDLPanel : public wxPanel {
  DECLARE_CLASS(EEditorSDLPanel)
  DECLARE_EVENT_TABLE()

  private:	
	//SDL_Surface *screen;
	ESDLEditorRender *edRender;
	void onPaint(wxPaintEvent &);
	void onEraseBackground(wxEraseEvent &);
	void onIdle(wxIdleEvent &);

  public:	
	EEditorSDLPanel(wxWindow *parent);
	~EEditorSDLPanel();
};
#endif