#pragma once
#include "wx/wx.h"
#include "MinesweepGUI.h"

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