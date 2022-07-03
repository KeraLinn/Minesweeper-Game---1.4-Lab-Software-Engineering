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
	wxButton** arrayOfButtonPtrs;


	void onButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

