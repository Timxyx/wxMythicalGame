#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame(const wxString &title);

private:
  void OnButtonClick(wxCommandEvent &event);

  wxButton *m_helloButton;
};

#endif // MAINFRAME_HPP
