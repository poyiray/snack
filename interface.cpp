#include "interface.h"

void 结算界面()
{
	string menu[2] = { "再来一局", "退出游戏" };
	SetCursor(55, 21);
	Color("你个垃圾 [选择a,d来进行选择][ENTER确认]", 2);

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

void 计分榜(int length)
{
	SetCursor(55, 10);
}
