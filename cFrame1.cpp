#include "cFrame1.h"

wxBEGIN_EVENT_TABLE(cFrame1, wxFrame)
	EVT_BUTTON(1003, ReloadImage)
wxEND_EVENT_TABLE()


cFrame1::cFrame1() : wxFrame(nullptr, wxID_ANY, "Cellular Automaton") {
	int h = wxDisplay().GetGeometry().GetHeight()/2;
	int w = 2 * h;
	this->SetPosition(wxPoint(0, 0));
	this->SetSize(wxSize(w, h));
	panel_im = new cMain(this, h, h);
	
	panel_controls = new ControlPanel(this,- 1, wxDefaultPosition, wxSize(w - h, h));

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(panel_im, 1, wxEXPAND);
	sizer->Add(panel_controls, 0, wxCENTER | wxALL, 10);
	this->SetSizerAndFit(sizer);
}

void cFrame1::ReloadImage(wxCommandEvent& evt)
{
	wxString ruletxt = panel_controls->rule_box->GetTextValue();
	std::string rule2 = std::string(ruletxt.mb_str());
	long long int rule = std::stoll(rule2);
	int resolution = panel_controls->resolution_box->GetValue();
	
	
	wxColor c0 = panel_controls->color_picker0->GetColour();
	wxColor c1 = panel_controls->color_picker1->GetColour();
	wxColor c2 = panel_controls->color_picker2->GetColour();

	std::vector<wxColor> colors = { c0, c1, c2 };

	panel_im->PresentImage(rule, resolution, colors);
	panel_im->Refresh();
}

