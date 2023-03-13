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
	//0 = ºÚÉ« 8 = »ÒÉ«
	//1 = À¶É« 9 = µ­À¶É«
	//2 = ÂÌÉ« 10 = µ­ÂÌÉ«
	//3 = Ç³ÂÌÉ« 11 = µ­Ç³ÂÌÉ«
	//4 = ºìÉ« 12 = µ­ºìÉ«
	//5 = ×ÏÉ« 13 = µ­×ÏÉ«
	//6 = »ÆÉ« 14 = µ­»ÆÉ«
	//7 = °×É« 15 = ÁÁ°×É«
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