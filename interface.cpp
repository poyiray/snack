#include "interface.h"

void �������()
{
	string menu[2] = { "����һ��", "�˳���Ϸ" };
	SetCursor(55, 21);
	Color("������� [ѡ��a,d������ѡ��][ENTERȷ��]", 2);

	SetCursor(63, 23);
	Color(menu[0] + "  ", 4);
	Color(menu[1] + "  ", 0);

	char enter = _getch();
	int choice = -1;

	while (enter != 13)
	{
		SetCursor(63, 23);
		if (enter == 'a')
		{
			choice = 0;
			Color(menu[0] + "  ", 4);
			Color(menu[1] + "  ", 0);
		}
		
		if (enter == 'd')
		{
			choice = 1;
			Color(menu[0] + "  ", 0);
			Color(menu[1] + "  ", 4);
		}
		enter = _getch();
	}
	
	if (choice == 1)
	{
		exit(EXIT_SUCCESS);
	}
	
	SetCursor(55, 21);
	cout << "                                                 ";

	SetCursor(63, 23);
	cout << "                                   ";
}

void �Ʒְ�(int length)
{
	SetCursor(55, 10);
}
