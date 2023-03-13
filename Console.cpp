#include "Console.h"

void HideCursor()
{
	HANDLE shandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cInfo;
	GetConsoleCursorInfo(shandle, &cInfo);
	cInfo.bVisible = false;
	SetConsoleCursorInfo(shandle, &cInfo);
}

void SetCursor(int x, int y)
{
	COORD coo;
	coo.X = x;
	coo.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coo);
	cout << "";
}

void Color(string str, int color)
{
	//0 = ��ɫ 8 = ��ɫ
	//1 = ��ɫ 9 = ����ɫ
	//2 = ��ɫ 10 = ����ɫ
	//3 = ǳ��ɫ 11 = ��ǳ��ɫ
	//4 = ��ɫ 12 = ����ɫ
	//5 = ��ɫ 13 = ����ɫ
	//6 = ��ɫ 14 = ����ɫ
	//7 = ��ɫ 15 = ����ɫ
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	cout << str;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

void SetConsoleSize(int width, int height)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT wrt = { 0,0,width - 1, height - 1 };
	SetConsoleWindowInfo(hOutput,TRUE, &wrt);
	COORD coord = { width,height };
	SetConsoleScreenBufferSize(hOutput, coord);
}