#include <wx/wx.h>
#include <wx/wxprec.h>
#include "EEditorSDLPanel.h"

#ifndef EEDITORFRAME
#define EEDITORFRAME
enum {
    IDF_FRAME = wxID_HIGHEST + 1,
    IDP_PANEL
};
class EEditorFrame : public wxFrame {
  DECLARE_CLASS(EEditorFrame)
  DECLARE_EVENT_TABLE()

  private:
	EEditorSDLPanel *panel;
	void onFileExit(wxCommandEvent &);
	void onHelpAbout(wxCommandEvent &);

  public:
	EEditorFrame();
	EEditorSDLPanel &getPanel();
};
#endif