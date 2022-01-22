#include "framework.h"
#include "shape_editor.h"

Shape* pcshape[101];
static int arrayCounter = 0;
static int check = 0;

ShapeObjectsEditor::ShapeObjectsEditor()
{
	pse = new PointEditor;
}

ShapeObjectsEditor::~ShapeObjectsEditor()
{
	for (int i = 0; i < arrayCounter; i++) 
		delete pcshape[i];
}

void ShapeObjectsEditor::StartPointEditor()
{
	if (pse) delete pse;
	pse = new PointEditor;
}

void ShapeObjectsEditor::StartLineEditor()
{
	if (pse) delete pse;
	pse = new LineEditor;
}

void ShapeObjectsEditor::StartRectEditor()
{
	if (pse) delete pse;
	pse = new RectEditor;
}

void ShapeObjectsEditor::StartEllipseEditor()
{
	if (pse) delete pse;
	pse = new EllipseEditor;
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse) 
		pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse) 
		pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse && check) 
		pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	ShapeEditor *draw = new ShapeEditor;
	draw->OnPaint(hWnd);
}

//ShapeEditor

void ShapeEditor::OnLBdown(HWND hWnd)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x1 = x2 = pt.x;
	y1 = y2 = pt.y;
	check = 1;
}

void ShapeEditor::OnLBup(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	check = 0;
}

void ShapeEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < arrayCounter; i++) {
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}

void ShapeEditor::OnMouseMove(HWND hWnd) {}

//Point

void PointEditor::OnLBdown(HWND hWnd) {
	__super::OnLBdown(hWnd);
}

void PointEditor::OnLBup(HWND hWnd) {
	__super::OnLBup(hWnd);
	PointShape* Point = new PointShape;
	Point->Set(x1, y1, x2, y2);
	pcshape[arrayCounter] = Point;
	arrayCounter++;
	InvalidateRect(hWnd, NULL, TRUE);
}

//Line 

void LineEditor::OnLBdown(HWND hWnd) {
	__super::OnLBdown(hWnd);
}

void LineEditor::OnLBup(HWND hWnd) {
	__super::OnLBup(hWnd);
	LineShape* Line = new LineShape;
	Line->Set(x1, y1, x2, y2);
	pcshape[arrayCounter] = Line;
	arrayCounter++;
	InvalidateRect(hWnd, NULL, TRUE);
}

void LineEditor::OnMouseMove(HWND hWnd) {
	POINT pt;
	HPEN hPen, hPenOld;
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

//Rect

void RectEditor::OnLBdown(HWND hWnd) {
	__super::OnLBdown(hWnd);
}

void RectEditor::OnLBup(HWND hWnd) {
	__super::OnLBup(hWnd);
	RectShape* Rect = new RectShape;
	Rect->Set(x1, y1, x2, y2);
	pcshape[arrayCounter] = Rect;
	arrayCounter++;
	InvalidateRect(hWnd, NULL, TRUE);
}

void RectEditor::OnMouseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPen, hPenOld;
	HDC hdc = GetDC(hWnd);
	int xñ1, yñ1;
	xñ1 = 2 * x1 - x2;
	yñ1 = 2 * y1 - y2;
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, xñ1, yñ1, NULL);
	LineTo(hdc, xñ1, y2);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x2, yñ1);
	LineTo(hdc, xñ1, yñ1);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	xñ1 = 2 * x1 - x2;
	yñ1 = 2 * y1 - y2;
	MoveToEx(hdc, xñ1, yñ1, NULL);
	LineTo(hdc, xñ1, y2);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x2, yñ1);
	LineTo(hdc, xñ1, yñ1);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

// Ellipse

void EllipseEditor::OnLBdown(HWND hWnd) {
	__super::OnLBdown(hWnd);
}


void EllipseEditor::OnLBup(HWND hWnd) {
	__super::OnLBup(hWnd);
	EllipseShape* Ellipse = new EllipseShape;
	Ellipse->Set(x1, y1, x2, y2);
	pcshape[arrayCounter] = Ellipse;
	arrayCounter++;
	InvalidateRect(hWnd, NULL, TRUE);
}

void EllipseEditor::OnMouseMove(HWND hWnd) {
	POINT pt;
	HPEN hPen, hPenOld;
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Arc(hdc, x1, y1, x2, y2, 0, 0, 0, 0);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	Arc(hdc, x1, y1, x2, y2, 0, 0, 0, 0);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}