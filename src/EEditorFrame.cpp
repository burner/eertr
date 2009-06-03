#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/dcbuffer.h>
#include <wx/image.h>
#include "EEditorFrame.h"
#include "EEditorSDLPanel.h"

inline void EEditorFrame::onFileExit(wxCommandEvent &) {
  Close();
}

EEditorSDLPanel &EEditorFrame::getPanel() {
  return *panel;
}

IMPLEMENT_CLASS(EEditorFrame, wxFrame)

BEGIN_EVENT_TABLE(EEditorFrame, wxFrame)
  EVT_MENU(wxID_EXIT, EEditorFrame::onFileExit)
  EVT_MENU(wxID_ABOUT, EEditorFrame::onHelpAbout)
END_EVENT_TABLE()

EEditorFrame::EEditorFrame() {
    Create(0, IDF_FRAME, wxT("EEditor"), wxDefaultPosition,
           wxDefaultSize, wxCAPTION | wxSYSTEM_MENU |
           wxMINIMIZE_BOX | wxCLOSE_BOX);

  wxMenuBar *mb = new wxMenuBar;

  wxMenu *fileMenu = new wxMenu;
  fileMenu->Append(wxID_EXIT, wxT("E&xit"));
  mb->Append(fileMenu, wxT("&File"));

  wxMenu *helpMenu = new wxMenu;
  helpMenu->Append(wxID_ABOUT, wxT("About"));
  mb->Append(helpMenu, wxT("&Help"));

  SetMenuBar(mb);

  panel = new EEditorSDLPanel(this);
}

void EEditorFrame::onHelpAbout(wxCommandEvent &) {
  wxMessageBox(wxT("EEditor made by Robert BuRnEr Schadek"), wxT("about EEditor"), wxOK | wxICON_INFORMATION);
}