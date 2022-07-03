#include "MinesweepGUI.h"

//defining the Event Table here using wx-macros, it takes name of class it is producing events for and the base class as parameters
wxBEGIN_EVENT_TABLE(MinesweepGUI, wxFrame)
	//EVT_BUTTON(1001, onButtonClicked)
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
	
	minefieldTracker = new int[fieldWidth * fieldHeight];
	
	//Cosmetics//
	wxFont myCustomFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont myCustomBombFont(24, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_MAX, wxFONTWEIGHT_EXTRABOLD, false);

	for (int x = 0; x < fieldWidth; x++) {
		for (int y = 0; y < fieldHeight; y++) {
			arrayOfButtonPtrs[y * fieldWidth + x] = new wxButton(this, 10000 + (y * fieldWidth +x));	//turns the 2D coordinates into 1D system for the array of buttons. Parent (this) is still the wxFrame, not the sizer
			arrayOfButtonPtrs[y * fieldWidth + x]->SetFont(myCustomFont);
			grid->Add(arrayOfButtonPtrs[y * fieldWidth + x], 1, wxEXPAND | wxALL);	   //adds array to grid-sizer, and the parameters wxEXPAND refers to dimensions of the grid-sizer, & wxALL refers to filling the entire space.
			arrayOfButtonPtrs[y * fieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MinesweepGUI::onButtonClicked, this);	  //Bind function connects the same function/event handler (onButtonClicked) to be associated with ALL buttons in the array, as opposed to using the event table above.
			minefieldTracker[y * fieldWidth + x] = 0; //default value for each location in minefield. 
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
	int x = (evt.GetId() - 10000) % fieldWidth;
	int y = (evt.GetId() - 10000) / fieldWidth;

	if (veryFirstClick) {	//generate minefield AFTER first click
		int mines = 30;
		//**IDEA to have user specify difficulty or # of mines? Also don't know if going to end up being able to resize the grid too, but if not, could have that too.

		while (mines) {
			int rx = rand() % fieldWidth;
			int ry = rand() % fieldHeight;

			if (minefieldTracker[ry * fieldWidth + rx] == 0 && rx != x && ry != y) {
				minefieldTracker[ry * fieldWidth + rx] = -1; //-1 is value for mine
				mines--;
			}
		}
		veryFirstClick = false; //after the first click, this sets to false so it doesn't activate again.
	}

	//disable button, to stop all interaction with particular object, in this case each button after pressed
	arrayOfButtonPtrs[y * fieldWidth + x]->Enable(false);

	//check if player hit mine
	if (minefieldTracker[y * fieldWidth + x] == -1) {
		wxMessageBox("BOOM! Game Over");



		//resetting game (reset first click, & setting all buttons back to blank/0)
		veryFirstClick = true;
		for (int x = 0; x < fieldWidth; x++) {
			for (int y = 0; y < fieldHeight; y++) {
				minefieldTracker[y * fieldWidth + x] = 0;
				arrayOfButtonPtrs[y * fieldWidth + x]->SetLabel("");
				arrayOfButtonPtrs[y * fieldWidth + x]->Enable(true);

			}
		}
	}
	else { //player did NOT hit mine
		//count neighbor cells that are mines
		int neighborMineCount = 0;
		for (int i = -1; i < 2; i++) {
			for(int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < fieldWidth && y + j >= 0 && y + j < fieldHeight) {
					if (minefieldTracker[(y + j) * fieldWidth + (x + i)] == -1) {
						neighborMineCount++;
					}
				}
			}
		}
		//update buttons to show mine count if > 0;
		if (neighborMineCount > 0) {
			arrayOfButtonPtrs[y * fieldWidth + x]->SetLabel(std::to_string(neighborMineCount));
		}
	}

	evt.Skip();		//this function allows the program to skip checking the parent window(s) for the button clicked function. AKA confirms that this event has been handled.
}
