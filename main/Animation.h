#pragma once
#include "Graphics.h"


class Background
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	bool fl = true;
	int r, g, b;
public:
	int x = 0, nach;
	void visBackground(HDC dc)
	{
		gr::Set_pen(dc, RGB(163, 223, 27), 1);
		if (cnt2 < 1) fl = true;
		if (cnt2 > 135) fl = false;
		if (fl) cnt2++;
		else cnt2--;
		if (cnt2 >= 0 && cnt2 < 35)
		{
			gr::Set_brush(dc, RGB(163, 223, 27), 1);
		}
		if (cnt2 >= 35 && cnt2 < 70)
		{
			gr::Set_brush(dc, RGB(134, 247, 84), 1);
		}
		if (cnt2 >= 70 && cnt2 < 105)
		{
			gr::Set_brush(dc, RGB(171, 247, 137), 1);
		}
		if (cnt2 >= 105 && cnt2 < 140)
		{
			gr::Set_brush(dc, RGB(255, 255, 255), 1);
		}
		
		
		POINT pt[4];
		pt[0] = { 0, heg * 2 / 3 };
		pt[1] = { 0, heg };
		pt[2] = { wid - 1, heg - 1 };
		pt[3] = { wid - 1, heg * 2 / 3 };
		Polygon(dc, pt, 4);
		gr::Set_pen(dc, RGB(153, 153, 153), 1);
		gr::Set_brush(dc, RGB(153, 153, 153), 1);
		pt[0] = { 0,  heg * 5 / 12 - 1 };
		pt[1] = { 0, heg * 2 / 3 - 1 };
		pt[2] = { wid - 1, heg * 2 / 3 - 1 };
		pt[3] = { wid - 1, heg * 5 / 12 - 1 };
		Polygon(dc, pt, 4);
		gr::Set_pen(dc, RGB(159, 197, 232), 1);
		gr::Set_brush(dc, RGB(159, 197, 232), 1);
		pt[0] = { 0,  0};
		pt[1] = { 0, heg * 5 / 12 - 1 };
		pt[2] = { wid - 1, heg * 5 / 12 - 1 };
		pt[3] = { wid - 1, 0};
		Polygon(dc, pt, 4);
		gr::Set_pen(dc, RGB(68, 68, 68), 12);
		nach = x;
		while (x < wid)
		{
			gr::Line(dc, x, heg * 7 / 14 + 20, x + 30, heg * 7 / 14 + 20);
			x += 70;
		}
		cnt3++;
	}
	
};

class Auto
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
public:
	int delt = 0;
	void visAvto(HDC dc)
	{
		gr::Set_pen(dc, RGB(0, 0, 0), 2);
		gr::Set_brush(dc, RGB(11, 83, 148), 1);
		POINT pt[10], pt2[4];
		pt[0] = { wid / 2 + 50, heg * 11 / 21 + delt};
		pt[1] = { wid / 2 + 43, heg * 11 / 21 + delt };
		pt[2] = { wid / 2 + 43, heg * 11 / 21 - 15 + delt };
		pt[3] = { wid / 2 + 50, heg * 11 / 21  - 15 + delt };
		pt[4] = { wid / 2 + 50, heg * 11 / 21 - 60 + delt };
		pt[5] = { wid / 2 + 70, heg * 11 / 21 - 60 + delt };
		pt[6] = { wid / 2 + 120, heg * 11 / 21 - 120 + delt };
		pt[7] = { wid / 2 + 300, heg * 11 / 21 - 120 + delt };
		pt[8] = { wid / 2 + 330, heg * 11 / 21 - 60 + delt };
		pt[9] = { wid / 2 + 330, heg * 11 / 21 + delt };
		Polygon(dc, pt, 10);
		gr::Set_brush(dc, RGB(207, 226, 243), 1);
		pt2[0] = { wid / 2 + 70, heg * 11 / 21 - 60 + delt };
		pt2[1] = { wid / 2 + 120, heg * 11 / 21 - 120 + delt };
		pt2[2] = { wid / 2 + 300, heg * 11 / 21 - 120 + delt };
		pt2[3] = { wid / 2 + 330, heg * 11 / 21 - 60 + delt };
		Polygon(dc, pt2, 4);
		gr::Set_brush(dc, RGB(0, 0, 0), 1);
		Ellipse(dc, wid / 2 + 75, heg * 11 / 21 - 35 + delt, wid / 2 + 135, heg * 11 / 21 + 25 + delt);
		Ellipse(dc, wid / 2 + 245, heg * 11 / 21 - 35 + delt, wid / 2 + 305, heg * 11 / 21 + 25 + delt);
		gr::Line(dc, wid / 2 + 190, heg * 11 / 21 - 120 + delt, wid / 2 + 190, heg * 11 / 21 + delt);
		gr::Line(dc, wid / 2 + 300, heg * 11 / 21 - 120 + delt, wid / 2 + 300, heg * 11 / 21 - 60 + delt);
		Ellipse(dc, wid / 2 + 170, heg * 11 / 21 - 53 + delt, wid / 2 + 185, heg * 11 / 21 - 45 + delt);
	}
};
class Snow
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	int x, y;
	COLORREF col;
public:
	Snow()
	{
		int wid = gr::GetWid();
		int heg = gr::GetHeg();
		x = rand() % wid;
		y = 3 * heg / 4 - rand() % (heg * 3 / 4);
		BYTE r, g, b;
		col = RGB(255, 255, 255);
	}
	void VisSnow(HDC dc)
	{
		int n;
		if (cnt2 >= 65 && cnt2 < 75) n = 35;
		if (cnt2 >= 75 && cnt2 < 90) n = 70;
		if (cnt2 >= 90 && cnt2 < 105) n = 140;
		if (cnt2 >= 105 && cnt2 < 120) n = 200;
		if (cnt2 >= 120 && cnt2 < 140) n = 250;
		Snow* snow = new Snow[n];
		int x2, y2, x1, y1;
		for (int i = 0; i < n; i++)
		{
			gr::Set_pen(dc, snow[i].col, 6);
			x2 = snow[i].x;
			y2 = snow[i].y;
			x1 = x2;	y1 = y2 + 2;
			gr::Line(dc, x2, y2, x1, y1);
		}
		delete[] snow;

	}
};

class Sun
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
public:
	int dx = 0;
	void VisSun(HDC dc)
	{

		if (cnt2 >= 0 && cnt2 < 35)
		{
			gr::Set_pen(dc, RGB(255, 255, 0), 15);
			gr::Set_brush(dc, RGB(255, 255, 0), 1);
			gr::Line(dc, wid - 70, 70, wid - 220, 70);
			gr::Line(dc, wid - 70, 70, wid - 160, 0);
			gr::Line(dc, wid - 70, 70, wid - 190, 150);
			gr::Line(dc, wid - 70, 70, wid - 120, 195);
			gr::Line(dc, wid - 70, 70, wid - 35, 200);
			gr::Line(dc, wid - 70, 70, wid, 120);
			gr::Line(dc, wid - 70, 70, wid, 60);
			gr::Line(dc, wid - 70, 70, wid - 20, 0);
			gr::Line(dc, wid - 70, 70, wid - 80, 0);
		}
		if (cnt2 >= 35 && cnt2 < 65)
		{
			gr::Set_pen(dc, RGB(238, 238, 74), 4);
			gr::Set_brush(dc, RGB(238, 238, 74), 1);
			gr::Line(dc, wid - 70, 70, wid - 220, 70);
			gr::Line(dc, wid - 70, 70, wid - 160, 0);
			gr::Line(dc, wid - 70, 70, wid - 190, 150);
			gr::Line(dc, wid - 70, 70, wid - 120, 195);
			gr::Line(dc, wid - 70, 70, wid - 35, 200);
			gr::Line(dc, wid - 70, 70, wid, 120);
			gr::Line(dc, wid - 70, 70, wid, 60);
			gr::Line(dc, wid - 70, 70, wid - 20, 0);
			gr::Line(dc, wid - 70, 70, wid - 80, 0);
		}
		if (cnt2 >= 65 && cnt2 < 105)
		{
			gr::Set_pen(dc, RGB(242, 242, 140), 2);
			gr::Set_brush(dc, RGB(242, 242, 140), 1);
		}
		if (cnt2 >= 105 && cnt2 < 140)
		{
			gr::Set_pen(dc, RGB(242, 242, 191), 2);
			gr::Set_brush(dc, RGB(242, 242, 191), 1);
		}
		
		Ellipse(dc, wid-140-dx, 10 , wid - 10-dx, 140);
		
	}
};

class Houses
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	int height[20] = { 50, 70, 90, 70, 190, 150, 120, 90, 60, 70, 150, 80, 200, 100, 110, 100, 200, 100, 180, 190 };
public:
	void VisHouses(HDC dc)
			{
				
				int x2, x1 = 0, y1 = heg * 5 / 12 - 1, y2;
				if (cnt == 20) cnt = 0;
				for (int i = 20 - cnt; i  < 20; i++)
				{
					POINT pt[4];
					gr::Set_pen(dc, RGB(0, 0, 0), 2);
					gr::Set_brush(dc, RGB((height[i]*5)%250, (height[i] * 4) % 250, (height[i] * 3) % 250), 1);
					x2 = x1 + 60;
					y2 = y1 - height[i];
					
					pt[0] = { x1, y1 };
					pt[1] = { x2, y1 };
					pt[2] = { x2, y2 };
					pt[3] = { x1, y2 };
					int pot = y2, pol = y1;
					Polygon(dc, pt, 4);
					while (pot + 25 < pol)
					{
						gr::Set_pen(dc, RGB(110, 110, 110), 2);
						gr::Set_brush(dc, RGB(159, 197, 232), 1);
						POINT pt2[4];
						pt2[0] = { x1 + 3, pot + 15 };
						pt2[1] = { x2 - 3, pot +  15 };
						pt2[2] = { x2 - 3, pot + 5 };
						pt2[3] = { x1 + 3, pot + 5};
						pot += 25;
						Polygon(dc, pt2, 4);
					}
					x1 += 65;
					gr::Set_pen(dc, RGB(0, 0, 0), 2);
					gr::Set_brush(dc, RGB(0, 0, 0), 1);
				}
				for (int i = 0; i < 20 - cnt; i++)
				{
					POINT pt[4];
					gr::Set_pen(dc, RGB(0, 0, 0), 2);
					gr::Set_brush(dc, RGB((height[i] * 5) % 250, (height[i] * 4) % 250, (height[i] * 3) % 250), 1);
					x2 = x1 + 60;
					y2 = y1 - height[i];
					
					pt[0] = { x1, y1 };
					pt[1] = { x2, y1 };
					pt[2] = { x2, y2 };
					pt[3] = { x1, y2 };
					int pot = y2, pol = y1;
					Polygon(dc, pt, 4);
					while (pot + 25 < pol)
					{
						gr::Set_pen(dc, RGB(110, 110, 110), 2);
						gr::Set_brush(dc, RGB(159, 197, 232), 1);
						POINT pt2[4];
						pt2[0] = { x1 + 3, pot + 15 };
						pt2[1] = { x2 - 3, pot + 15 };
						pt2[2] = { x2 - 3, pot + 5 };
						pt2[3] = { x1 + 3, pot + 5 };
						pot += 25;
						Polygon(dc, pt2, 4);
					}
					x1 += 65;
					gr::Set_pen(dc, RGB(0, 0, 0), 2);
					gr::Set_brush(dc, RGB(0, 0, 0), 1);
				}
				if (!ost)
					cnt++;
				Sleep(60);
			}
};

class Svet
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	int dist = -700;
	bool move = true, light = false;
	int cnt4 = 0;
public:
	void VisSvet(HDC dc)
	{
		
		POINT pt2[4];
		pt2[0] = { dist, 300};
		pt2[1] = { dist + 10, 300};
		pt2[2] = { dist + 10, 200};
		pt2[3] = { dist, 200};
		POINT pt3[4];
		pt3[0] = { dist + 20, 200 };
		pt3[1] = { dist - 15, 200 };
		pt3[2] = { dist - 15, 120 };
		pt3[3] = { dist + 20, 120 };
		gr::Set_pen(dc, RGB(0, 0, 0), 2);
		gr::Set_brush(dc, RGB(0, 0, 0), 1);
		Polygon(dc, pt2, 4);
		Polygon(dc, pt3, 4);
		if (light)
		{
			gr::Set_pen(dc, RGB(0, 255, 0), 2);
			gr::Set_brush(dc, RGB(0, 255, 0), 1);
			Ellipse(dc, dist - 10, 165, dist + 15, 190);
		}
		else
		{
			gr::Set_pen(dc, RGB(255, 0, 0), 2);
			gr::Set_brush(dc, RGB(255, 0, 0), 1);
			Ellipse(dc, dist - 10, 125, dist + 15, 150);
			
		}
		if (!move)
		{
			cnt4++;
			ost = true;
		}

		if (cnt4 > 15)
		{
			ost = false;
			cnt4 = 0;
			light = true;
			move = true;
		}
		if (move)
		{
			dist += 55;
		}
		if (dist > 30 && dist < 100)
		{
			move = false;
		}


		if (dist > 5000)
		{
			light = false;
			dist = -700;
		}
		
	}

};

class Flower
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	
public:
	COLORREF col;
	int x, y, r, g, b;
	Flower()
	{
		x = rand() % wid;
		y = heg - 1 - rand() % (heg / 3);
		r = rand() % 250, g = rand() % 250, b = rand() % 250;
		col = RGB(r, g, b);
	}
	void VisFlower(HDC dc)
	{
		int ng;
		if (!ost) {
			flow.clear();
			if (cnt2 >= 0 && cnt2 < 35) ng = 70;
			if (cnt2 >= 35 && cnt2 < 70) ng = 50;
			if (cnt2 >= 70 && cnt2 < 105) ng = 20;
			if (cnt2 >= 105 && cnt2 < 140) ng = 0;

			Flower* flower = new Flower[ng];
			int x2, y2, x1, y1;
			for (int i = 0; i < ng; i++)
			{
				vector<int>tmp(5);
				COLORREF col = flower[i].col;
				x2 = flower[i].x;
				y2 = flower[i].y;
				x1 = x2 + 5;	y1 = y2;
				gr::Set_pen(dc, RGB(50, 160, 27), 4);
				gr::Line(dc, (x2 + x1) / 2., (y2 + y1) / 2., (x2 + x1) / 2., (y2 + y1) / 2. + 13);
				gr::Set_pen(dc, col, 8);
				gr::Line(dc, x2, y2, x1, y1);
				tmp[0] = x2; tmp[1] = y2; tmp[2] = flower[i].r, tmp[3] = flower[i].g, tmp[4] = flower[i].b;
				flow.push_back(tmp);
			}
			delete[] flower;
		}
		else
		{
			int x2, y2, x1, y1;
			for (int i = 0; i < flow.size(); i++)
			{
				x2 = flow[i][0] + 5;	y2 = flow[i][1];
				x1 = x2 + 5;	y1 = y2;
				gr::Set_pen(dc, RGB(50, 160, 27), 4);
				gr::Line(dc, (x2 + x1) / 2., (y2 + y1) / 2., (x2 + x1) / 2., (y2 + y1) / 2. + 13);
				COLORREF color = RGB(flow[i][2], flow[i][3], flow[i][4]);
				gr::Set_pen(dc, color, 8);
				gr::Line(dc, x2, y2, x1, y1);
			}
		}

		Sleep(60);
		
	}
};
class Animation
{
private:
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
public:
	void animate(HDC dc)
	{
		Background back;
		Svet svet;
		back.x = 0;
		char input;
		Sun sun;
		Auto avto;
		while (true)
		{

			if (_kbhit())
			{
				input = _getch();
				if (input=='w')
					avto.delt = 0;
				if (input == 's')
					avto.delt = 70;
			}


			back.visBackground(dc);
			if (!ost)
				back.x += -20 - wid;
			else
				back.x = back.nach;
			if (cnt2 > 65)
			{
				Snow snow;
				snow.VisSnow(dc);
			}
			
			sun.VisSun(dc);
			Houses houses;
			houses.VisHouses(dc);
			svet.VisSvet(dc);
			
			avto.visAvto(dc);
			Flower flower;
			flower.VisFlower(dc);
			BitBlt(gr::dc, 0, 0, wid, heg, gr::dcMem, 0, 0, SRCCOPY);
		}
	}
};