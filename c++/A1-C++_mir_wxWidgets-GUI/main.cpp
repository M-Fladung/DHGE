#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit() override {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Hello wxWidgets on WSL!");
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
