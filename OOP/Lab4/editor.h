#pragma once

class Editor
{
public:
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND hWnd) = 0;
	virtual void OnMouseMove(HWND hWnd) = 0;
	virtual void OnPaint(HWND hWnd) = 0;
};