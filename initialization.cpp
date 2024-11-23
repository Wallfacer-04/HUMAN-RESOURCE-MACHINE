#include "initialization.h"

//机器人位置初始化 a

int main()
{
	/*for (int i = 1; i <= Height; i++)//看看wide调多大
	{
		for (int j = 1; j <= Wide; j++)
			cout << "#";
		cout << endl;
	}*/
	initrobot();
	initwood();
	initUI();//画出机器人等
	system("pause");
	return 0;
}
void initrobot()
{
	int k = 40;
	int p = 21;
	for (int i = 1; i <= 5; i++)
	{
		robot.body[i].X = WIDE / 2 - k + i;//头上，5个-
		robot.body[i].Y = HEIGHT / 2 - p;
	}
	robot.body[6].X = WIDE / 2 - k+1;//头左，|
	robot.body[6].Y = HEIGHT / 2 - p + 1;
	robot.body[7].X = WIDE / 2 - k + 6-1;//头右，|
	robot.body[7].Y = HEIGHT / 2 - p + 1;
	for (int i = 8; i <= 12; i++)
	{
		robot.body[i].X = WIDE / 2 - k + (i - 7);//头下，5个-
		robot.body[i].Y = HEIGHT / 2 - p + 2;
	}
	robot.body[13].X = WIDE / 2 - k + 2;//左手，/
	robot.body[13].Y = HEIGHT / 2 - p + 3;
	robot.body[14].X = WIDE / 2 - k + 4;//右手，\

	robot.body[14].Y = HEIGHT / 2 - p + 3;
	robot.body[15].X = WIDE / 2 - k + 1;//左手，/
	robot.body[15].Y = HEIGHT / 2 - p + 4;
	robot.body[16].X = WIDE / 2 - k + 5;//右手，\

	robot.body[16].Y = HEIGHT / 2 - p + 4;
	for (int i = 17; i <= 21; i++)
	{
		robot.body[i].X = WIDE / 2 - k + (i - 16);//横着，5个-
		robot.body[i].Y = HEIGHT / 2 - p + 5;
	}
	robot.body[22].X = WIDE / 2 - k + 2;//脚|
	robot.body[22].Y = HEIGHT / 2 - p + 6;
	robot.body[23].X = WIDE / 2 - k + 4;//脚|
	robot.body[23].Y = HEIGHT / 2 - p + 6;
	robot.size = 23;
	return;
}
void initwood()
{
	for (int i = 0; i < 6; i++)
	{
		inwood.body[i].X = 5;
		inwood.body[i].Y = 1+3*i;
	}//初始化inwood输入传送带
	for (int i = 0; i < 4;i++)
	{
		emptywood.body[i].X = 15+5*i;
		emptywood.body[i].Y = 11;
	}//初始化emptywood空地
	for (int i = 0; i < 4; i++)
	{
		outwood.body[i].X = 40;
		outwood.body[i].Y = 1 + 3 * i;
	}//初始化outwood传送带

	return;
}
//初始化界面控界
void initUI()
{
	//画机器人
	PrintRobot();
	//画inwood传送带
	PrintInwood();
	//画emptywood空地
	PrintEmptywood();
	//画outwood传送带
	PrintOutwood();
	/*for (int i = 0; i < 6; i++)
	{
		PrintWood(outwood.body[i].X, outwood.body[i].Y, 'X');
	}*/
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
}
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
	}
	return;
}
void PrintInwood()
{
	PrintIN();
	//画inwood传送带
	for (int i = 0; i < 6; i++)
	{
		PrintWood(inwood.body[i].X, inwood.body[i].Y, 'X');
	}
}

void PrintOutwood()
{
	//画Outwood传送带
	PrintOUT();
	for (int i = 0; i < 4; i++)
	{
		PrintWood(outwood.body[i].X, outwood.body[i].Y, 'X');
	}
	return;
}

void PrintEmptywood()
{
	//画emptywood传送带
	for (int i = 0; i < 4; i++)
	{
		PrintWood(emptywood.body[i].X, emptywood.body[i].Y, 'X');
		Print(emptywood.body[i].X + 2, emptywood.body[i].Y + 3, i+48);
	}
	return;
}
//画出竖线
void PrintLine()
{

}
//打印emptywood的编号
void Print(int x,int y,char c)
{
	COORD coord = { 0 };		//光标结构体定义
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar(c);
	return;
}
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
void PrintWood(int x,int y,char number)
{
	COORD coord = { 0 };		//光标结构体定义
	for(int i=0;i<3;i++)
		for (int j = 0; j < 5; j++)
		{
			coord.X = x+j;
			coord.Y = y+i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			if ((j == 0 || j == 4) && (i == 0 || i == 2)) putchar('+');
			else if (i == 0 || i == 2) putchar('-');
			else if (j == 0 || j == 4) putchar('|');
			else if (j == 2) putchar(number);
		}
	return;
}
