#include "framework.h"
#include "resource2_2.h"

static INT_PTR CALLBACK Work2_2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)FALSE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)FALSE;
		}
		if (LOWORD(wParam) == IDBACK)
		{
			EndDialog(hDlg, -1);
			return (INT_PTR)FALSE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
int Func_Work2_2(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2_2), hWnd, Work2_2);
}