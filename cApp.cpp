#include "cApp.h"


wxIMPLEMENT_APP(cApp);


cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	m_frame1 = new cFrame1();
	m_frame1->Show();
	m_frame1->CenterOnScreen();
	return true;
}