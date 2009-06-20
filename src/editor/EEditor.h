#include <wx/wxprec.h>
#include <wx/wx.h>
#include "EEditorFrame.h"
#include "EEditorSDLPanel.h"

#ifndef EEDITOR
#define EEDITOR
class EEditor : public wxApp {
  DECLARE_CLASS(EEditor)

  private:
	///Main EEditor frame
	EEditorFrame *frame;

  public:
	bool OnInit();
	int OnRun();
	int OnExit();
};
#endif