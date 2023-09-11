#include "mainframe.hpp"

MainFrame::MainFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)) {
  // Create a button
  m_helloButton = new wxButton(this, wxID_ANY, wxT("Click Me!"),
                               wxPoint(50, 50), wxDefaultSize);

  // Bind the button click event to the OnButtonClick function
  m_helloButton->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);

  // Show the frame
  Show(true);
}

void MainFrame::OnButtonClick(wxCommandEvent &event) {
  wxMessageBox("Hello World", "Message", wxOK | wxICON_INFORMATION);
}
