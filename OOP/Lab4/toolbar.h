#pragma once
#include "framework.h"
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

class Toolbar 
{
private:
	HWND hWndToolBar;
public:
	void OnCreate(HWND);
	void OnSize(HWND);
	void OnNotify(HWND, LPARAM, WPARAM);
};
