#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "unit.hpp"
#include <wx/grid.h>
#include <wx/wx.h>
class MainFrame : public wxFrame {
public:
  MainFrame(const wxString &title);

private:
  void OnButtonClick(wxCommandEvent &event);
  void SaveCurrentUnit(wxCommandEvent &event);
  void listClick(wxCommandEvent &event);
  void renderTable(wxCommandEvent &event);
  Unit *getUnitByType(wxString tpe);

  wxButton *m_helloButton;
  wxMenuBar *m_pMenuBar;
  wxMenu *m_pFileMenu;
  wxMenu *m_pHelpMenu;
  wxListBox *unit_list;
  wxCheckBox *checkBox;
  wxStaticBitmap *imageControl;
  wxStaticText *type_label;
  wxStaticText *hp_label;
  wxStaticText *moves_label;
  wxStaticText *weapons_label;
  wxGrid *grid;
  wxGridStringTable *table;
  std::vector<Unit *> existing_units;
  wxBitmap bitmap;
};

#endif // MAINFRAME_HPP
