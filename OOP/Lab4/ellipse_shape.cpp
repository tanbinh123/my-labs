#include "framework.h"
#include "ellipse_shape.h"


void EllipseShape::Show(HDC hdc, bool isDash) {
	HPEN hPen, hPenOld;
	HBRUSH hBrush, hBrushOld;
	if (isDash) {
		hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
	}
	else {
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
		SelectObject(hdc, hBrush);
		Ellipse(hdc, xs1, ys1, xs2, ys2);
		SelectObject(hdc, hBrushOld);
		DeleteObject(hBrush);
	}
};

Shape* EllipseShape::Copy() {
	return new EllipseShape();
}

