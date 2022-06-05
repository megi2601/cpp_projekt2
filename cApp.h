#pragma once

#include "wx/wx.h"
#include "cMain.h"
#include "cFrame1.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();
private:
	cMain* m_frame2 = nullptr;
	cFrame1* m_frame1 = nullptr;
public:
	virtual bool OnInit();
};

