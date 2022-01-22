#pragma once
#include "shape.h"
#include "editor.h"

class ShapeEditor : public Editor
{
protected:
	int x1, y1, x2, y2;
public: 
	ShapeEditor() : x1{0}, y1{0}, x2{0}, y2{0} {}
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND); //додатковий інтерфейсний метод
};

class ShapeObjectsEditor
{
private:
	ShapeEditor *pse = NULL;
public:
	ShapeObjectsEditor();
	~ShapeObjectsEditor();
	void StartPointEditor(HWND);
	void StartLineEditor(HWND);
	void StartRectEditor(HWND);
	void StartEllipseEditor(HWND);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND);
};

class PointEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnInitMenuPopup(HWND);
};

class LineEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
	void OnLBup(HWND);
	void OnInitMenuPopup(HWND);
};

class RectEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
	void OnLBup(HWND);
	void OnInitMenuPopup(HWND);
};

class EllipseEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
	void OnLBup(HWND);
	void OnInitMenuPopup(HWND);
};
