#include "MinesweepGUI.h"

//defining the Event Table here using wx-macros, it takes name of class it is producing events for and the base class as parameters
wxBEGIN_EVENT_TABLE(MinesweepGUI, wxFrame)
	EVT_BUTTON(1001, OnButtonClicked)
wxEND_EVENT_TABLE()

//replaces the tutorial video's cMain
MinesweepGUI::MinesweepGUI() : wxFrame(nullptr, wxID_ANY, "Lab 1.4 - Minesweeper", wxPoint(30,30), wxSize(800,600))
{
	myFirstButton = new wxButton(this, 1001, "Click Me", wxPoint(10,10), wxSize(150, 50));    //before, had wxID_ANY as second parameter, when creating the event for button clicking, had to specify ID & change it here
	myFirstTextbox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	myFirstListBox = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));

}

MinesweepGUI::~MinesweepGUI()
{
}


void MinesweepGUI::onButtonClicked(wxCommandEvent& evt)
{
	myFirstListBox->AppendString(myFirstTextbox->GetValue());	//can use wxString and std::string class interchangably
	evt.Skip();
}
