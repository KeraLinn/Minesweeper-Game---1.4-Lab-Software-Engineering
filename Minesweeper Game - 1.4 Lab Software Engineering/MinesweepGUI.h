#pragma once
#include "wx/wx.h"

//replaces the tutorial video's cMain
class MinesweepGUI : public wxFrame
{
public:
	MinesweepGUI();
	~MinesweepGUI();

public:
	/*original code for this program
	wxButton* myFirstButton = nullptr;
	wxTextCtrl* myFirstTextbox = nullptr;
	wxListBox* myFirstListBox = nullptr;*/
	int fieldWidth = 10;
	int fieldHeight = 10;
	wxButton** arrayOfButtonPtrs; //replaces tutorial's variable btn

	int* minefieldTracker = nullptr; //replaces tutorial's variable nField
	bool veryFirstClick = true; //at this point is when the minefield generates, else user could click on a minefield immediately.
	//replaces tutorial's variable bFirstClick

	void onButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

