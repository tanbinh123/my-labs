#include "shape.h"

class MyEditor {
public:
	int x1, y1, x2, y2;
	~MyEditor();
	void Start(Shape *);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};