#pragma once
#include "wx/wx.h"
#include "wx/frame.h"
#include "CellsCalc.h"
#include "wx/custombgwin.h"



class cMain : public wxCustomBackgroundWindow<wxPanel>
{
public:
	cMain(wxWindow*, int, int);
	~cMain();
	wxImage MakeImage(std::vector<std::vector<int>>, int, std::vector<wxColor>);
	void PresentImage(long long int, int, std::vector<wxColor>);
private:
	//wxDECLARE_EVENT_TABLE();
};

