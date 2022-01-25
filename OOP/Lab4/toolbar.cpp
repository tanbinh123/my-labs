#include "toolbar.h"
#include "lab2.h"

void Toolbar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hWndToolBar)
    {
        GetClientRect(hWnd, &rc);
        GetWindowRect(hWndToolBar, &rw);
        MoveWindow(hWndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
}

void Toolbar::OnCreate(HWND hWndmother)
{
    HINSTANCE hInst = (HINSTANCE)GetWindowLong(hWndmother, GWL_HINSTANCE);
    TBBUTTON tbb[6];
    ZeroMemory(tbb, sizeof(tbb));
    tbb[0].iBitmap = 0;
    tbb[0].fsState = TBSTATE_ENABLED;
    tbb[0].fsStyle = TBSTYLE_BUTTON;
    tbb[0].idCommand = IDM_POINT;

    tbb[1].iBitmap = 1;
    tbb[1].fsState = TBSTATE_ENABLED;
    tbb[1].fsStyle = TBSTYLE_BUTTON;
    tbb[1].idCommand = IDM_LINE;

    tbb[2].iBitmap = 2;
    tbb[2].fsState = TBSTATE_ENABLED;
    tbb[2].fsStyle = TBSTYLE_BUTTON;
    tbb[2].idCommand = IDM_RECTANGLE;

    tbb[3].iBitmap = 3;
    tbb[3].fsState = TBSTATE_ENABLED;
    tbb[3].fsStyle = TBSTYLE_BUTTON;
    tbb[3].idCommand = IDM_ELLIPSE;

    tbb[4].iBitmap = 4;
    tbb[4].fsState = TBSTATE_ENABLED;
    tbb[4].fsStyle = TBSTYLE_BUTTON;
    tbb[4].idCommand = IDM_CUBE;

    tbb[5].iBitmap = 5;
    tbb[5].fsState = TBSTATE_ENABLED;
    tbb[5].fsStyle = TBSTYLE_BUTTON;
    tbb[5].idCommand = IDM_OLINEO;

    SendMessage(hWndToolBar, TB_ADDBUTTONS, 6, (LPARAM)&tbb);
    hWndToolBar = CreateToolbarEx(hWndmother,
        WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS, IDC_TOOLBAR,
        6, hInst, IDB_TOOLBAR,
        tbb,
        6,
        24, 24, 24, 24,
        sizeof(TBBUTTON));
}

void Toolbar::OnNotify(HWND hWnd, LPARAM lParam, WPARAM wParam)
{
    LPNMHDR pnmh = (LPNMHDR)lParam;
    if (pnmh->code == TTN_NEEDTEXT)
    {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
        switch (lpttt->hdr.idFrom)
        {
        case IDM_POINT:
            lstrcpy(lpttt->szText, L"Точка");
            break;
        case IDM_LINE:
            lstrcpy(lpttt->szText, L"Лінія");
            break;
        case IDM_RECTANGLE:
            lstrcpy(lpttt->szText, L"Прямокутник");
            break;
        case IDM_ELLIPSE:
            lstrcpy(lpttt->szText, L"Еліпс");
            break;
        case IDM_CUBE:
            lstrcpy(lpttt->szText, L"Куб");
            break;
        case IDM_OLINEO:
            lstrcpy(lpttt->szText, L"Лінія з кружечками");
            break;
        default: lstrcpy(lpttt->szText, L"Нічого");
        }
    }
}