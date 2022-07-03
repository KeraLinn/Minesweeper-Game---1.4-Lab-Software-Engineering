#include "MinesweepAppLaunch.h"
wxIMPLEMENT_APP(MinesweepAppLaunch);

//replaces the tutorial video's cApp

MinesweepAppLaunch::MinesweepAppLaunch()
{

}

MinesweepAppLaunch::~MinesweepAppLaunch()
{

}

bool MinesweepAppLaunch::OnInit()
{
	displayWindow = new MinesweepGUI();
	displayWindow->Show();
	return true;
}