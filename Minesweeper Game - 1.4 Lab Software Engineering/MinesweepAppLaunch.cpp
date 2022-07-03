#include "MinesweepAppLaunch.h"
wxIMPLEMENT_APP(MinesweepAppLaunch);

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