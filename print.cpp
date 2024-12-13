//每次使用之前先initrobot（）
#include "base.h"
void PrintRobot()
{
	COORD coord = { 0 };		//光标结构体定义
	//画机器人
	for (int i = 1; i <= robot.size; i++)
	{
		coord.X = robot.body[i].X;
		coord.Y = robot.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		if (i == 6 || i == 7 || i == 22 || i == 23) putchar('|');
		else if (i == 13 || i == 15) putchar('/');
		else if (i == 14 || i == 16) putchar('\\');
		else if (i != 1 && i != 5 && i != 8 && i != 12) putchar('-');
		else if (i == 1 || i == 5) putchar('.');
	}
	return;
}
//每次使用之前先initrobot（）
void deleterobot()
{
	COORD coord = { 0 };		//光标结构体定义
	//擦除之前的机器人
	for (int i = 1; i <= robot.size; i++)
	{
		coord.X = robot.body[i].X;
		coord.Y = robot.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar(' ');
	}
	return;
}
void PrintInwood()
{
	PrintIN();
	//画inwood传送带
	for (int i = 0; i < 6; i++)
	{
		PrintWood(inwood.body[i].X, inwood.body[i].Y, "X");
	}
}
//inwood   x=5,y=1
void PrintEmptywood(int k)
{
	//画emptywood传送带
	for (int i = 0; i < k; i++)
	{
		PrintWood(emptywood.body[i].X, emptywood.body[i].Y, "X");
		setposition(emptywood.body[i].X + 2, emptywood.body[i].Y + 3);
		putchar(i + 48);
	}
	return;
}
//emptywood   x=15,y=11
void PrintOutwood()
{
	//画Outwood传送带
	PrintOUT();
	for (int i = 0; i < 6; i++)
	{
		PrintWood(outwood.body[i].X, outwood.body[i].Y, "X");
	}
	return;
}
//outwood    x=40,y=1
//画出竖线 位置：x=55 1~18行
void PrintLine()
{
	COORD coord = { 0 };		//光标结构体定义
	for (int i = 1; i <= 18; i++)
	{
		coord.X = 55;
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar('|');
	}
}
//打印emptywood的编号

//IN的位置：X=0，Y=3
void PrintIN()
{
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 0;
	coord.Y = 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	cout << "IN";
	return;
}
//OUT的位置：X=48,Y=3
void PrintOUT()
{
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 48;
	coord.Y = 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	cout << "OUT";
	return;
}
//打印Wood块
void PrintWood(int x, int y, string number)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			setposition(x + j, y + i);	//设置光标位置
			if ((j == 0 || j == 4) && (i == 0 || i == 2)) putchar('+');
			else if (i == 0 || i == 2) putchar('-');
			else if (j == 0 || j == 4) putchar('|');
		}
	Printnum(x + 2, y + 1, number);
	//isnowwood = true;
	return;
}
//指令行界面
//X=57,Y=1
void Printnum(int x, int y, string s)//分别处理输出长度1,2,3的情况 
{
	int len = s.length();
	setposition(x - 1, y);
	if (s[0] == '-')
	{
		cout << s;
		if (len == 2) putchar(' ');
	}
	else
	{
		putchar(' ');
		cout << s;
		if (len == 1) putchar(' ');
	}
	return;
}
void PrintCode()
{
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 57;
	coord.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	for (int i = 0; i < 5; i++)
		putchar('=');
	cout << " CODE ";
	for (int i = 0; i < 5; i++)
		putchar('=');
	return;
}
void deletenowwood()
{
	COORD coord = { 0 };		//光标结构体定义
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			coord.X = nowx + 1 + j;
			coord.Y = nowy - 3 + i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			putchar(' ');
		}
	return;
}

void movetoleft()
{
	Hide(); //隐藏光标
	adjustspeed();//调速 
	initrobot(nowx, nowy);
	deleterobot();
	deletenowwood();
	if (isnowwood)
	{
		PrintWood(nowx - 1 + 1, nowy - 3, nowwood);
	}
	nowx--;
	initrobot(nowx, nowy);
	PrintRobot();
	Sleep(speed);
}
void movetoright()
{
	Hide();//隐藏光标 
	void adjustspeed();//调速 
	initrobot(nowx, nowy);
	deleterobot();
	deletenowwood();
	if (isnowwood)
	{
		PrintWood(nowx + 1 + 1, nowy - 3, nowwood);
	}
	nowx++;
	initrobot(nowx, nowy);
	PrintRobot();
	Sleep(speed);
}

void adjustspeed()//在toleft和right的时候判断就行 
{
	if (_kbhit())//判断用户是否按按键，不阻塞读入 
	{
		char ch = _getch();
		if (ch == '1') speed = 150;
		if (ch == '2') speed = 100;
		if (ch == '3') speed = 75;
		if (ch == '4') speed = 25;
		if (ch == '5') speed = 5;
	}
}

void setposition(int x, int y)//设置光标位置
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Hide()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	return;
}
