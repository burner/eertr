#include <wx/wx.h>
#include <iostream>
#include "EEditor.h"
#include "EEditorFrame.h"
#include "EEditorSDLPanel.h"
bool EEditor::OnInit() {
  frame = new EEditorFrame;
  frame->SetClientSize(800, 480);
  frame->Centre();
  frame->Show();

  SetTopWindow(frame);

  return true;
}

int EEditor::OnRun() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	std::cerr<<"Unable to init SDL: "<<SDL_GetError()<<std::endl;
	return -1;
  }
  wxIdleEvent event;
  event.SetEventObject(&frame->getPanel());
  frame->getPanel().AddPendingEvent(event);

  // start the main loop
  return wxApp::OnRun();
}

int EEditor::OnExit() {
  SDL_Quit();

  return wxApp::OnExit();
}
IMPLEMENT_CLASS(EEditor, wxApp);
IMPLEMENT_APP(EEditor)