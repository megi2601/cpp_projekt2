#pragma once
#include"wx/wx.h"
#include "wx/clrpicker.h"
#include "wx/spinctrl.h"

class ControlPanel : public wxPanel
{
public:
	ControlPanel(wxWindow*, wxWindowID, wxPoint, wxSize);
	wxSpinCtrlDouble* rule_box;
	wxSpinCtrl* resolution_box;
	wxButton* reload_button;
	wxColourPickerCtrl* color_picker0;
	wxColourPickerCtrl* color_picker1;
	wxColourPickerCtrl* color_picker2;
	wxStaticText* text1;
	wxStaticText* text2;
	wxStaticText* text3;
	wxStaticText* rule_txt;
	wxStaticText* resol_txt;
};

