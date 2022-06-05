#pragma once
#include "wx/wx.h"
#include "wx/display.h"
#include "cMain.h"
#include "ControlPanel.h"
#include <string>


class cFrame1 : public wxFrame
{
public:
	cFrame1();
	void ReloadImage(wxCommandEvent& evt);
	cMain* panel_im;
	ControlPanel* panel_controls;
	wxDECLARE_EVENT_TABLE();
};

