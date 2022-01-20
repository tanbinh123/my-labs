#pragma once
#include "framework.h"

class Shape
{
	protected:
		long xs1, ys1, xs2, ys2;
	public:
		Shape() : xs1{0}, ys1{0}, xs2{0}, ys2{0} {}
		void Set(long x1, long y1, long x2, long y2);
		virtual void Show(HDC hdc) = 0;
};

class PointShape : public Shape
{
	void Show(HDC hdc);
};

class LineShape : public Shape
{
	void Show(HDC hdc);
};

class RectShape : public Shape
{
	void Show(HDC hdc);
};

class EllipseShape : public Shape
{
	void Show(HDC hdc);
};