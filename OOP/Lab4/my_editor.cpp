#include "framework.h"
#include "my_editor.h"

int arrayCounter = 0;
static int check = 0;
Shape* pcshape[101];

MyEditor::~MyEditor() {
	for (int i = 0; i < arrayCounter; i++)
		delete pcshape[i];
}

void MyEditor::Start(Shape* shape) {
	pcshape[arrayCounter] = shape;
}

void MyEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x1 = x2 = pt.x;
	y1 = y2 = pt.y;
	check = 1;
}

void MyEditor::OnLBup(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	check = 0;
	pcshape[arrayCounter]->Set(x1, y1, x2, y2);

	arrayCounter++;
	InvalidateRect(hWnd, NULL, TRUE);
	pcshape[arrayCounter] = pcshape[arrayCounter - 1]->Copy();
}

void MyEditor::OnMouseMove(HWND hWnd) {
	if (check) {
		POINT pt;
		HDC hdc = GetDC(hWnd);

		SetROP2(hdc, R2_NOTXORPEN);

		MoveToEx(hdc, x1, y1, NULL);
		pcshape[arrayCounter]->Set(x1, y1, x2, y2);
		pcshape[arrayCounter]->Show(hdc, 1);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		x2 = pt.x;
		y2 = pt.y;

		MoveToEx(hdc, x1, y1, NULL);
		pcshape[arrayCounter]->Set(x1, y1, x2, y2);
		pcshape[arrayCounter]->Show(hdc, 1);

		ReleaseDC(hWnd, hdc);
	}
}

void MyEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < arrayCounter; i++) {
		if (pcshape[i]) pcshape[i]->Show(hdc, 0);
	}
	EndPaint(hWnd, &ps);
}