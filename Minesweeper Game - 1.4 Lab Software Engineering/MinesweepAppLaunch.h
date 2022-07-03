#pragma once
#include "wx/wx.h"
#include "MinesweepGUI.h"


//replaces the tutorial video's cApp
class MinesweepAppLaunch : public wxApp
{
public:
	MinesweepAppLaunch();
	~MinesweepAppLaunch();

private:
	MinesweepGUI* displayWindow = nullptr;

public:
	virtual bool OnInit();
};