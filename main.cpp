#include "frames.h"

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
  // Crea la ventana principal
  MainFrame* mainFrame = new MainFrame("Blockchain");

  // Muestra la ventana
  mainFrame->Show(true);

  // Indica que la aplicación ha sido inicializada con éxito
  return true;
}

wxIMPLEMENT_APP(MyApp);
