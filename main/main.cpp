#pragma once
#include "Graphics.h"
#include "Animation.h"

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand((unsigned)time(NULL));
	ifstream fin("result.txt"); //объект для чтения с файла
	::system("mode con cols=120 lines=45");
	hWnd = GetConsoleWindow();
	gr::InitGraphics(hWnd);
	int wid = gr::GetWid();
	int heg = gr::GetHeg();
	Sleep(50);
	Animation anim;
	anim.animate(gr::dcMem); //вызываем анимацию

	string str; int res;
	fin >> str;
	fin.close();
	ofstream fout("result.txt"); //объект для записи в файл
	res = stoi(str);

	//сравнение текущего результата с рекордом

	if (res < cnt3)
	{
		fout << cnt3;
	}
	else
	{
		fout << res;
	}

	cout << "\n\n\t\t\t\t\t  RECORD: " << max(res, cnt3); //вывод рекорда на экран

	fout.close();

	BitBlt(gr::dc, 0, 0, wid, heg, gr::dcMem, 0, 0, SRCCOPY);
	cin.get();




	return 0;
}
