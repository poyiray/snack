#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<random>
using namespace std;

void HideCursor();

void SetCursor(int x, int y);

void Color(string str, int color);

void SetConsoleSize(int width, int height);