#include "framework.h"
#include "point_shape.h"

void PointShape::Show(HDC hdc, bool isDash) {
	SetPixel(hdc, xs1, ys1, RGB(0, 0, 0));
}

Shape* PointShape::Copy() {
	return new PointShape();
}

