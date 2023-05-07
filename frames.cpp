#include "frames.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
  wxPanel* panel = new wxPanel(this);
  wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Proyecto de Blockchain", wxPoint(300,400));
}
