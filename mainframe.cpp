#include "mainframe.hpp"
#include "unit.hpp"
#include <fstream>
#include <string>
#include <vector>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

MainFrame::MainFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)) {
  // Create a button
  // m_helloButton = new wxButton(this, wxID_ANY, wxT("Click Me!"),
  //                              wxPoint(300, 50), wxDefaultSize);

  // Bind the button click event to the OnButtonClick function
  // m_helloButton->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);
  m_pMenuBar = new wxMenuBar();
  m_pFileMenu = new wxMenu();
  m_pFileMenu->Append(wxID_OPEN, _T("&Open"));
  m_pFileMenu->Append(wxID_SAVE, _T("&Save"));
  m_pFileMenu->AppendSeparator();
  m_pFileMenu->Append(wxID_EXIT, _T("&Quit"));
  m_pMenuBar->Append(m_pFileMenu, _T("&File"));
  m_pHelpMenu = new wxMenu();
  m_pHelpMenu->Append(wxID_ABOUT, _T("&About"));
  m_pMenuBar->Append(m_pHelpMenu, _T("&Help"));
  // m_pHelpMenu->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);
  Bind(wxEVT_MENU, &MainFrame::OnButtonClick, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &MainFrame::SaveCurrentUnit, this, wxID_SAVE);

  SetMenuBar(m_pMenuBar);
  grid = new wxGrid(this, wxID_ANY, wxPoint(300, 250), wxSize(400, 300));
  grid->EnableEditing(false);
  table = new wxGridStringTable(1, 4);

  grid->HideColLabels();
  grid->HideRowLabels();

  table->SetValue(0, 0, "Sample Data");
  for (int row = 0; row < grid->GetNumberRows(); ++row) {
    for (int col = 0; col < grid->GetNumberCols(); ++col) {
      grid->SetReadOnly(row, col, true);
    }
  }
  grid->SetTable(table);

  type_label =
      new wxStaticText(this, wxID_ANY, "", wxPoint(300, 10), wxSize(100, 35));
  hp_label =
      new wxStaticText(this, wxID_ANY, "", wxPoint(300, 40), wxSize(100, 35));
  moves_label =
      new wxStaticText(this, wxID_ANY, "", wxPoint(300, 80), wxSize(100, 35));
  weapons_label = new wxStaticText(this, wxID_ANY, "Weapons", wxPoint(300, 110),
                                   wxSize(100, 35));

  checkBox = new wxCheckBox(this, wxID_ANY, "Show stats", wxPoint(30, 735),
                            wxSize(100, 70));

  Elvish_Archer *archer = new Elvish_Archer("Archer");
  Dwarvish_Fighter *fighter = new Dwarvish_Fighter("Fighter");
  Drake_Burner *burner = new Drake_Burner("Burner");

  existing_units = {archer, fighter, burner};
  wxArrayString wxUnitNames;
  for (const auto &e_unit : existing_units) {
    wxUnitNames.Add(e_unit->type_name());
  }

  unit_list = new wxListBox(this, wxID_ANY, wxPoint(0, 0), wxSize(260, 750),
                            wxUnitNames, wxLB_SINGLE | wxLB_HSCROLL,
                            wxDefaultValidator);

  unit_list->Bind(wxEVT_LISTBOX, &MainFrame::listClick, this);

  wxBitmap bitmap("./images/elvish_archer.png", wxBITMAP_TYPE_PNG);
  imageControl = new wxStaticBitmap(this, wxID_ANY, bitmap, wxPoint(700, 0),
                                    wxSize(200, 200));
  // Show the frame
  Show(true);
}

void MainFrame::OnButtonClick(wxCommandEvent &event) {
  wxMessageBox("Hello World", "Message", wxOK | wxICON_INFORMATION);
}
void MainFrame::SaveCurrentUnit(wxCommandEvent &event) {
  // wxMessageBox("Hello World", "Message", wxOK | wxICON_INFORMATION);
  std::cout << "Label here " << type_label->GetLabel() << std::endl;
  std::ofstream textfile;
  textfile.open("savefile.txt");

  // textfile << GetLabel(); not working because the GetLabel return value is a
  // wxString;
  textfile << std::string(type_label->GetLabel().mb_str());

  textfile.close();
}
void MainFrame::listClick(wxCommandEvent &event) {
  std::string img;

  switch (str2int(event.GetString())) {
  case str2int("Elvish Archer"):
    img = "./images/elvish_archer.png";

    break;
  case str2int("Drake Burner"):
    img = "./images/drake_burner.png";

    break;
  case str2int("Dwarvish Fighter"):
    img = "./images/dwarvish_fighter.png";
  }
  wxBitmap bitmap(img, wxBITMAP_TYPE_PNG);
  imageControl->SetBitmap(bitmap);

  renderTable(event);
}
Unit *MainFrame::getUnitByType(wxString tpe) {
  for (const auto &e_unit : existing_units) {
    if (tpe == (std::string)e_unit->type_name()) {
      return e_unit;
    }
  }
}
void MainFrame::renderTable(wxCommandEvent &event) {
  Unit *current_unit = getUnitByType(event.GetString());
  // std::cout << current_unit->name() << std::endl;
  type_label->SetLabel(current_unit->type_name());
  hp_label->SetLabel(wxString::Format(wxT("%i"), current_unit->max_health()));
  moves_label->SetLabel(wxString::Format(wxT("%i"), current_unit->moves()));
  int num_rows = 0;
  for (auto &wp : *current_unit->weapons()) {
    num_rows++;
  }
  table = new wxGridStringTable(num_rows, 4);
  int i = 0;

  for (auto &wp : *current_unit->weapons()) {
    table->SetValue(i, 0, wp.name());
    i++;
  }
  grid->SetTable(table);
  grid->ForceRefresh();
  for (int row = 0; row < grid->GetNumberRows(); ++row) {
    for (int col = 0; col < grid->GetNumberCols(); ++col) {
      grid->SetReadOnly(row, col, true);
    }
  }
}
