#pragma once
#include "shape.h"

class PointShape : public Shape
{
	void Show(HDC, bool isDash);
	Shape* Copy();
};