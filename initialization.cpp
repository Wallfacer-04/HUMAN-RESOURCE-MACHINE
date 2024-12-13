#include "base.h"
//初始化界面控界,设定机器人位置，inwood，outwood，emptywood
void initUI1()
{
	initrobot(20, 4);
	initwood();

	//画机器人
	PrintRobot();
	//画inwood传送带
	PrintInwood();
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 7;
	coord.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar('1');
	coord.X = 7;
	coord.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar('2');
	//无emptywood空地
	//PrintEmptywood();
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();
	//将光标移动到最下方防止干扰
	coord.X = 0;
	coord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
}
void initUI2()
{
	initrobot(20, 4);
	initwood();

	//画机器人
	PrintRobot();
	//画inwood传送带
	PrintInwood();
	setposition(7, 2);//设置光标位置
	putchar('3');
	setposition(7, 5);//设置光标位置
	putchar('9');
	setposition(7, 8);
	putchar('5');
	setposition(7, 11);
	putchar('1');
	setposition(6, 14);
	cout << -2;
	setposition(6, 17);
	cout << -2;
	//画出emptywood空地
	PrintEmptywood(3);
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();
}
void initUI3()
{
	initrobot(20, 4);
	initwood();

	//画机器人
	PrintRobot();
	//画inwood传送带
	PrintInwood();
	setposition(7, 2);//设置光标位置
	putchar('6');
	setposition(7, 5);//设置光标位置
	putchar('2');
	setposition(7, 8);
	putchar('7');
	setposition(7, 11);
	putchar('7');
	setposition(6, 14);
	cout << -9;
	setposition(7, 17);
	cout << 3;
	//画出emptywood空地
	PrintEmptywood(3);
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();
}

//初始化robot、wood的变量信息
// 
//robot左上角坐标：x=20,y=4
void initrobot(int k, int p)
{
	for (int i = 1; i <= 5; i++)
	{
		robot.body[i].X = k + i;//头上，5个-
		robot.body[i].Y = p;
	}
	robot.body[6].X = k + 1;//头左，|
	robot.body[6].Y = p + 1;
	robot.body[7].X = k + 6 - 1;//头右，|
	robot.body[7].Y = p + 1;
	for (int i = 8; i <= 12; i++)
	{
		robot.body[i].X = k + (i - 7);//头下，5个-
		robot.body[i].Y = p + 2;
	}
	robot.body[13].X = k + 2;//左手，/
	robot.body[13].Y = p + 3;
	robot.body[14].X = k + 4;//右手，\

	robot.body[14].Y = p + 3;
	robot.body[15].X = k + 1;//左手，/
	robot.body[15].Y = p + 4;
	robot.body[16].X = k + 5;//右手，\

	robot.body[16].Y = p + 4;
	for (int i = 17; i <= 21; i++)
	{
		robot.body[i].X = k + (i - 16);//横着，5个-
		robot.body[i].Y = p + 5;
	}
	robot.body[22].X = k + 2;//脚|
	robot.body[22].Y = p + 6;
	robot.body[23].X = k + 4;//脚|
	robot.body[23].Y = p + 6;
	robot.body[1].X = k + 2;//眼睛
	robot.body[1].Y = p + 1;
	robot.body[5].X = k + 4;//眼睛
	robot.body[5].Y = p + 1;
	robot.size = 23;
	return;
}

void initwood()
{
	for (int i = 0; i < 6; i++)
	{
		inwood.body[i].X = 5;
		inwood.body[i].Y = 1 + 3 * i;
	}//初始化inwood输入传送带  x=5,y=1
	for (int i = 0; i < 4; i++)
	{
		emptywood.body[i].X = 15 + 5 * i;
		emptywood.body[i].Y = 11;
	}//初始化emptywood空地  x=15 y=11
	for (int i = 0; i < 6; i++)
	{
		outwood.body[i].X = 40;
		outwood.body[i].Y = 1 + 3 * i;
	}//初始化outwood传送带 x=40 y=1

	return;
}
