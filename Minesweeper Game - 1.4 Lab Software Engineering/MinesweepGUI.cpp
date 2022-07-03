#include "MinesweepGUI.h"


//replaces the tutorial video's cMain
MinesweepGUI::MinesweepGUI() : wxFrame(nullptr, wxID_ANY, "Lab 1.4 - Minesweeper", wxPoint(30,30), wxSize(800,600))
{
	myFirstButton = new wxButton(this, wxID_ANY, "Click Me", wxPoint(10,10), wxSize(150, 50));
	myFirstTextbox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	myFirstListBox = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));

}

MinesweepGUI::~MinesweepGUI()
{
}
