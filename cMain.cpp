#include "cMain.h"
#include "CellsCalc.h"


//wxBEGIN_EVENT_TABLE(cMain, wxFrame)
//wxEND_EVENT_TABLE()


cMain::cMain(wxWindow* parent, int w, int h) {
	Create(parent,-1,wxDefaultPosition, wxSize(w, h));
	//int rule = 2625597481100;
	//int rule = 4228243060787;
	//int resolution = 5;
	//PresentImage(rule, resolution);
}

cMain::~cMain() {

}

wxImage cMain::MakeImage(std::vector<std::vector<int>> states, int resolution, std::vector<wxColor> colors) {
	int w = states[0].size();
	int h = states.size();
	int square_size = resolution;
	wxImage im = wxImage(square_size * w, square_size * h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int x = square_size * j;
			int y = square_size * i;
			wxRect r = wxRect(x, y, square_size, square_size);
			wxColor c = colors[states[i][j]];
			im.SetRGB(r, c.Red(), c.Green(), c.Blue());
		}
	}
	return im;
}

void cMain::PresentImage(long long int rule, int resolution, std::vector<wxColor> colors) {
	int w = this->GetClientSize().x;
	int h = this->GetClientSize().y;
	int steps = h/resolution;
	int cells = w / resolution;
	CellsCalc c = CellsCalc();
	int_vec first_state = c.random_state(cells);
	std::vector<int_vec> evol = c.evolution(first_state, rule, steps);
	wxImage im = MakeImage(evol, resolution, colors);
	wxBitmap bitmap(im);
	this->SetBackgroundBitmap(bitmap);
}

