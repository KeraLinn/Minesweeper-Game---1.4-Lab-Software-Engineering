#include "MinesweepGUI.h"

//defining the Event Table here using wx-macros, it takes name of class it is producing events for and the base class as parameters
wxBEGIN_EVENT_TABLE(MinesweepGUI, wxFrame)
	//orig. code for orig single button "Click me"	//EVT_BUTTON(1001, onButtonClicked)
wxEND_EVENT_TABLE()

//replaces the tutorial video's cMain
MinesweepGUI::MinesweepGUI() : wxFrame(nullptr, wxID_ANY, "Lab 1.4 - Minesweeper", wxPoint(30,30), wxSize(800,600))
{
	//original code for program
	//myFirstButton = new wxButton(this, 1001, "Click Me", wxPoint(10,10), wxSize(150, 50));    //before, had wxID_ANY as second parameter, when creating the event for button clicking, had to specify ID & change it here
	//myFirstTextbox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//myFirstListBox = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	arrayOfButtonPtrs = new wxButton * [fieldWidth * fieldHeight];
	wxGridSizer* grid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);
	for (int x = 0; x < fieldWidth; x++) {
		for (int y = 0; y < fieldHeight; y++) {
			arrayOfButtonPtrs[y * fieldWidth + x] = new wxButton(this, 10000 + (y * fieldWidth +x));	//turns the 2D coordinates into 1D system for the array of buttons. Parent (this) is still the wxFrame, not the sizer
			grid->Add(arrayOfButtonPtrs[y * fieldWidth + x], 1, wxEXPAND | wxALL);	   //adds array to grid-sizer, and the parameters wxEXPAND refers to dimensions of the grid-sizer, & wxALL refers to filling the entire space.
			arrayOfButtonPtrs[y * fieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MinesweepGUI::onButtonClicked, this);	  //Bind function connects the same function/event handler (onButtonClicked) to be associated with ALL buttons in the array, as opposed to using the event table above.
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

MinesweepGUI::~MinesweepGUI()
{
	delete[] arrayOfButtonPtrs;
}


void MinesweepGUI::onButtonClicked(wxCommandEvent& evt)
{
	//original code for program:
	//myFirstListBox->AppendString(myFirstTextbox->GetValue());	//can use wxString and std::string class interchangably

	//get coordinate of button in arrayOfButtonPtrs AKA specify which button was clicked
	int x = (evt.GetId() - 1000) % fieldWidth;
	int y = (evt.GetId() - 1000) / fieldWidth;

	evt.Skip();		//this function allows the program to skip checking the parent window(s) for the button clicked function. AKA confirms that this event has been handled.
}
