#include "Console.h"
#include "interface.h"

const int MAP_X = 24, Margin_left = 5;
const int MAP_Y = 24, Margin_top = 1;
string Map[MAP_Y][MAP_X] =
{
	{"■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■" },
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","◆","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","◆","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","◆","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","■"},
	{"■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■" }
};

string state = "停止";
int timer = 15;
int PlayerX[MAP_X * MAP_Y] = { 10,11,12 };
int PlayerY[MAP_X * MAP_Y] = { 10,10,10 };
int length = 2;
string result = "无";
char 方向 = ' ';

void Collection()
{
	int min = 1, max = 23;
	random_device seed;//硬件生成随机数种子
	ranlux48 engine(seed());//利用种子生成随机数引擎
	uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为均匀分布
	int randomX = distrib(engine);//随机数
	int randomY = distrib(engine);//随机数

	//Map[randomY][randomX] == "●" || 

	timer++;
	if (timer == 16)
	{
		for (int i = 0; i < 2; i++)
		{
			while (randomY == 0 || randomY == MAP_Y - 1 || randomX == 0 || randomX == MAP_X - 1 || Map[randomY][randomX] == "◆" || randomY > MAP_Y - 1 || randomX > MAP_X - 1)
			{
				randomX = distrib(engine);//随机数
				randomY = distrib(engine);//随机数
			}
			Map[randomY][randomX] = "◆";
		}
		timer = 0;
	}
}

void ResetMap()
{
	if (result != "无")
	{
		result = "无";
		state = "停止";
		timer = 15;
		方向 = ' ';
		
		for (int i = 0; i <= length; i++)
		{
			PlayerX[i] = 0;
			PlayerY[i] = 0;
		}
		length = 2;

		PlayerX[0] = 10;
		PlayerX[1] = 11;
		PlayerX[2] = 12;

		PlayerY[0] = 10;
		PlayerY[1] = 10;
		PlayerY[2] = 10;
	}

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (i == 0 || i == MAP_Y - 1 || j == 0 || j == MAP_X - 1)
			{
				Map[i][j] = "■";
			}
			else
			{
				Map[i][j] = "  ";
			}
		}
	}
	Collection();
}

void printMap()
{
	HideCursor();
	for (int i = 0; i <= length; i++)
	{
		Map[PlayerY[i]][PlayerX[i]] = "●";
	}

	int y = Margin_top;
	for (int i = 0; i < MAP_Y; i++)
	{
		SetCursor(Margin_left, y);
		for (int j = 0; j < MAP_X; j++)
		{
			//给指定方块 用 颜色打印
			if (Map[i][j] == "■")
			{
				Color(Map[i][j], 2);
			}
			else if (Map[i][j] == "●" && (PlayerY[length] != i || PlayerX[length] != j))
			{
				Color(Map[i][j], 1);
			}
			else if (PlayerY[length] == i && PlayerX[length] == j)
			{
				Color(Map[i][j], 6);
			}
			else if (Map[i][j] == "◆")
			{
				Color(Map[i][j], 12);
			}
			else
			{
				cout << Map[i][j];
			}
		}
		y++;
	}
	
}

void 移动判断()
{
	if (Map[PlayerY[length + 1]][PlayerX[length + 1]] == "◆")
	{
		length++;
	}
	else
	{
		Map[PlayerY[0]][PlayerX[0]] = "  ";
		for (int i = 0; i <= length; i++)
		{
			PlayerY[i] = PlayerY[i + 1];
			PlayerX[i] = PlayerX[i + 1];
		}
		PlayerY[length + 1] = 0;
		PlayerX[length + 1] = 0;
	}
}

void Movement()
{
	if (方向 == 'w')
	{
		state = "向上";
		PlayerY[length + 1] = PlayerY[length] - 1;
		PlayerX[length + 1] = PlayerX[length];
	}

	if (方向 == 's')
	{
		state = "向下";
		PlayerY[length + 1] = PlayerY[length] + 1;
		PlayerX[length + 1] = PlayerX[length];
	}

	if (方向 == 'a')
	{
		state = "向左";
		PlayerX[length + 1] = PlayerX[length] - 1;
		PlayerY[length + 1] = PlayerY[length];
	}

	if (方向 == 'd')
	{
		state = "向右";
		PlayerX[length + 1] = PlayerX[length] + 1;
		PlayerY[length + 1] = PlayerY[length];
	}

	if (方向 != ' ')
	{
		移动判断();
	}
}

void Check()
{
	if (PlayerY[length] == 0 || PlayerY[length] == MAP_Y - 1 || PlayerX[length] == 0 || PlayerX[length] == MAP_X - 1)
	{
		result = "失败";
		结算界面();
		ResetMap();
	}

	for (int i = 0; i < length; i++)
	{
		if (PlayerX[length] == PlayerX[i] && PlayerY[length] == PlayerY[i])
		{
			result = "失败";
			结算界面();
			ResetMap();
		}
	}
}

int main() { 
	ios::sync_with_stdio(false);
	SetConsoleTitleA("贪吃蛇"); //设置一个新标题
	SetConsoleSize(100, 30); //设置窗口大小
	ResetMap();

	while (true)
	{
		while (!_kbhit())
		{
			Movement();
			Check();
			Collection();
			printMap();
			Sleep(122);
		}

		方向 = _getch();

		//防止用户 让蛇往反方向走
		if (length != 0)
		{
			if (state == "向上" && 方向 == 's')
			{
				方向 = 'w';
			}
			if (state == "向下" && 方向 == 'w')
			{
				方向 = 's';
			}
			if (state == "向左" && 方向 == 'd')
			{
				方向 = 'a';
			}
			if (state == "向右" && 方向 == 'a')
			{
				方向 = 'd';
			}
		}
	}
	system("pause");
	return 0;
}