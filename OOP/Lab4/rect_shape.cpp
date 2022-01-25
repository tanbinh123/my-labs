#include "framework.h"
#include "rect_shape.h"

void RectShape::Show(HDC hdc, bool isDash) {
	HPEN hPen, hPenOld;
	if (isDash) {
		hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs1, ys2);
		LineTo(hdc, xs2, ys2);
		LineTo(hdc, xs2, ys1);
		LineTo(hdc, xs1, ys1);
	}
	else {
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs1, ys2);
		LineTo(hdc, xs2, ys2);
		LineTo(hdc, xs2, ys1);
		LineTo(hdc, xs1, ys1);
	}
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

Shape* RectShape::Copy() {
	return new RectShape();
}
