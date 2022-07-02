#pragma once
#include "wx/wx.h"

class MinesweepAppLaunch : public wxApp
{
public:
	MinesweepAppLaunch();
	~MinesweepAppLaunch();

public:
	virtual bool OnInit();
};