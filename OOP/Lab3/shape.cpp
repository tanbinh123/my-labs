#include "framework.h"
#include "shape.h"

void Shape::Set(long x1, long y1, long x2, long y2) {
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}

void PointShape::Show(HDC hdc) {
	SetPixel(hdc, xs1, ys1, RGB(0, 0, 0));
}


void LineShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);
	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);
}



void RectShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, xs1, ys1, xs2, ys2);
	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);
}

void EllipseShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255)); //створюється пензль
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
	DeleteObject(hBrush);
}