#pragma once
#include "rect_shape.h"
#include "line_shape.h"

class CubeShape : public RectShape, public LineShape {
public:
	void Show(HDC, bool isDash);
	Shape* Copy();
};