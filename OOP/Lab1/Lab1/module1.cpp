#include "framework.h"
#include "resource1.h"

static WCHAR buf[256];
static int pos = 1;

static INT_PTR CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hWndScroll = GetDlgItem(hDlg, IDC_SCROLLBAR1);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SetScrollRange(hWndScroll, SB_CTL, 1, 100, TRUE);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, 1);
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)FALSE;
		}
		break;
	case WM_HSCROLL:
		pos = GetScrollPos(hWndScroll, SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT: 
			pos--;
			break;
		case SB_LINERIGHT: 
			pos++;
			break;
		case SB_THUMBPOSITION: 
		case SB_THUMBTRACK: 
			pos = HIWORD(wParam);
			break;
		default: break;
		}
		SetScrollPos(hWndScroll, SB_CTL, pos, TRUE); 
			break;
	}
	return (INT_PTR)FALSE;
}
int Func_Work1(HINSTANCE hInst, HWND hWnd, WCHAR* dest)
{
	if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1))
	{
		_itow_s(pos, buf, 10);
		lstrcpyW(dest, buf);
	}
	return 1;
}