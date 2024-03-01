#pragma once

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
//=============================================================================

HWND hWnd;

class Graphics
{
private:
	static HPEN hPen;
	static HBRUSH hBrush;
	static HBITMAP bmMem;
	static HANDLE  hOld;
	static int wid, heg;
public:
	static HDC dc;
	static HDC dcMem;

	static void Set_pen(HDC, COLORREF, int);
	static void Set_brush(HDC, COLORREF, bool);
	static void Line(HDC, int, int, int, int);
	static void Point(HDC, int, int, COLORREF);
	static void Osi(HDC);
	static int GetWid() { return wid; }
	static int GetHeg() { return heg; }
	//����� �������������� ���������������
	//��������� � ��������
	static void WinCoor(POINT&, const double, const double);
	//����� �������������� ��������
	//��������� � ���������������
	static void NormCoor(const POINT, double&, double&);

	static void InitGraphics(HWND);
	~Graphics();
};
HBRUSH Graphics::hBrush = NULL;
HPEN Graphics::hPen = NULL;
HDC Graphics::dc = NULL;
HDC Graphics::dcMem = NULL;
HBITMAP Graphics::bmMem = NULL;
HANDLE  Graphics::hOld = NULL;
int Graphics::wid = 0;
int Graphics::heg = 0;

//����������� �������� ���������,
//������������ �������� ���������� ������
void Graphics::InitGraphics(HWND hWnd)
{
	RECT rect;
	GetClientRect(hWnd, &rect);
	wid = rect.right;
	heg = rect.bottom;
	dc = GetDC(hWnd);
	Set_pen(dc, RGB(255, 255, 255), 1);
	Set_brush(dc, RGB(255, 255, 255), true);

	//��������� �������� ������, �����������
	//� ���������� ����������� ��������� ����������
	dcMem = CreateCompatibleDC(Graphics::dc);

	//��� ��������� � ������ �� �� ����� ���� ���������� ���������,
	//�������� ������. ��� ����� ������ ������������
	//������� �����(HBITMAP).
	//� ������ ����� �������� �� ������� �����
	bmMem = CreateCompatibleBitmap(Graphics::dc, wid, heg);

	// �������� ������� ����� � �������� ������
	hOld = SelectObject(dcMem, bmMem);
}

Graphics::~Graphics()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteObject(bmMem);
	DeleteDC(dcMem);
	ReleaseDC(hWnd, dc);
	DeleteDC(dc);
}

//� ������� Set_pen() � Set_brush()
//����� ��������� ����� �������� (���� � �����)
//���������� ������� ������
void Graphics::Set_pen(HDC dc, COLORREF col, int w)
{
	DeleteObject(hPen);
	hPen = CreatePen(PS_INSIDEFRAME, w, col);
	SelectObject(dc, hPen);
}
void Graphics::Set_brush(HDC dc, COLORREF col, bool empty)
{
	DeleteObject(hBrush);
	empty ? hBrush = ::CreateSolidBrush(col) :
		hBrush = ::CreateSolidBrush(NULL_BRUSH);
	::SelectObject(dc, hBrush);
}
void Graphics::Line(HDC dc, int x1, int y1, int x2, int y2)
{
	MoveToEx(dc, x1, y1, NULL);
	LineTo(dc, x2, y2);
}
void Graphics::Point(HDC dc, int x, int y, COLORREF col)
{
	SetPixel(dc, x, y, col);
}
void Graphics::Osi(HDC dc)
{
	Set_pen(dc, RGB(255, 0, 0), 1);
	Line(dc, 0, heg / 2, wid - 1, heg / 2);
	Set_pen(dc, RGB(0, 255, 0), 1);
	Line(dc, wid / 2, 0, wid / 2, heg - 1);
}

void Graphics::WinCoor(POINT& pt, const double fx, const double fy)
{
	pt.x = int((fx + 1.f) * (wid / 2.f));
	pt.y = heg - int((fy + 1.f) * (heg / 2.f));
}

void Graphics::NormCoor(const POINT pt, double& fx, double& fy)
{
	fx = (pt.x - wid / 2.f) / (wid / 2.f);
	fy = (heg / 2.f - pt.y) / (heg / 2.f);
}

//��������������� Graphics
typedef Graphics gr;
int cnt = 0, cnt2 = 0, cnt3 = 0; 	bool ost = false;
vector<vector <int>> flow;
