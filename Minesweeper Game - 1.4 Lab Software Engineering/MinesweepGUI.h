#pragma once

#include "wx/wx.h"

//replaces the tutorial video's cMain
class MinesweepGUI : public wxFrame
{
public:
	MinesweepGUI();
	~MinesweepGUI();

public:
	wxButton* myFirstButton = nullptr;
	wxTextCtrl* myFirstTextbox = nullptr;
	wxListBox* myFirstListBox = nullptr;

};

