#include "ControlPanel.h"
#include "text.h"



ControlPanel::ControlPanel(wxWindow* parent, wxWindowID id, wxPoint p, wxSize s) : wxPanel(parent, id, p, s) {
	
	wxFont f(13, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	this->SetFont(f);

	int panel_w = this->GetClientSize().GetWidth();
	int panel_h = this->GetClientSize().GetHeight();

	
	rule_box = new wxSpinCtrlDouble(this, 1001, "", wxDefaultPosition);
	rule_box->SetRange(0, 7625597484986);
	rule_box->SetIncrement(1);
	rule_box->SetValue(6665197224986);
	rule_txt = new wxStaticText(this, 1011, "Enter rule:   ");

	resolution_box = new wxSpinCtrl(this, 1002, "", wxDefaultPosition);
	resolution_box->SetRange(1, 20);
	resolution_box->SetValue(5);
	resolution_box->SetSize(wxSize(60, wxDefaultSize.GetHeight()));
	resol_txt =  new wxStaticText(this, 1011, "Enter resolution:   ");

	reload_button = new wxButton(this, 1003, "Reload!");

	color_picker0 = new wxColourPickerCtrl(this, 1004);
	color_picker0->SetColour(wxString("red"));
	color_picker1 = new wxColourPickerCtrl(this, 1005);
	color_picker1->SetColour(wxString("green"));
	color_picker2 = new wxColourPickerCtrl(this, 1006);
	color_picker2->SetColour(wxString("blue"));
	wxStaticText* cp_text0 = new wxStaticText(this, wxID_ANY, "State 0:");
	wxStaticText* cp_text1 = new wxStaticText(this, wxID_ANY, "State 1:");
	wxStaticText* cp_text2 = new wxStaticText(this, wxID_ANY, "State 2:");
	wxBoxSizer* sc0 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* sc1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* sc2 = new wxBoxSizer(wxVERTICAL);
	sc0->Add(cp_text0, 0, wxALIGN_CENTER_HORIZONTAL);
	sc0->Add(color_picker0);
	sc1->Add(cp_text1, 0, wxALIGN_CENTER_HORIZONTAL);
	sc1->Add(color_picker1);
	sc2->Add(cp_text2, 0, wxALIGN_CENTER_HORIZONTAL);
	sc2->Add(color_picker2);
	wxBoxSizer* sizer_colors = new wxBoxSizer(wxHORIZONTAL);
	sizer_colors->Add(sc0, 0, wxALIGN_CENTER);
	sizer_colors->Add(sc1, 0, wxALIGN_CENTER);
	sizer_colors->Add(sc2, 0, wxALIGN_CENTER);


	text1 = new wxStaticText(this, 1007,"", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	//text2 = new wxStaticText(this, 1008, "");
	text1->SetLabel(text_source1);
	text1->Wrap(panel_w);


	
	wxBoxSizer* sizer_rule = new wxBoxSizer(wxHORIZONTAL);
	sizer_rule->Add(rule_txt, 0, wxALIGN_CENTER_VERTICAL);
	sizer_rule->Add(rule_box, 0);

	wxBoxSizer* sizer_resolution = new wxBoxSizer(wxHORIZONTAL);
	sizer_resolution ->Add(resol_txt, 0, wxALIGN_CENTER_VERTICAL);
	sizer_resolution->Add(resolution_box, 0);

	

	wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
	main_sizer->Add(text1, 0, wxEXPAND | wxALL, 15);
	//main_sizer->Add(text2, 0, wxEXPAND | wxBOTTOM, 10);

	main_sizer->Add(sizer_rule, 0, wxALIGN_CENTRE_HORIZONTAL | wxALL,  7);
	main_sizer->Add(sizer_resolution, 0, wxALIGN_CENTRE_HORIZONTAL | wxBOTTOM, 10);
	main_sizer->Add(sizer_colors, 0, wxALIGN_CENTRE_HORIZONTAL | wxALL, 10);
	main_sizer->Add(reload_button, 0, wxALIGN_CENTRE_HORIZONTAL | wxALL, 15);

	this->SetSizerAndFit(main_sizer);
}



