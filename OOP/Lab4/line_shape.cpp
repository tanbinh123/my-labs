#include "framework.h"
#include "line_shape.h"

void LineShape::Show(HDC hdc, bool isDash) {
	HPEN hPen, hPenOld;
	if (isDash) {
		hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
	}
	else {
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
	}

	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

Shape* LineShape::Copy() {
	return new LineShape();
}
