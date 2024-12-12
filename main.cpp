#include "initialization.cpp"
#include "print.cpp"
#include "function.cpp"
#include "operatestring.cpp"
#include "judge.cpp"
#include "play.cpp"
#include "base.h"
#define _CRT_SECUER_NO_WARNINGS
//机器人位置初始化

int main()
{
	/*for (int i = 1; i <= Height; i++)//看看wide调多大
	{
		for (int j = 1; j <= Wide; j++)
			cout << "#";
		cout << endl;
	}*/
	for(int i=0;i<20;i++)
		input[i][0]='X';
	for(int i=0;i<20;i++)
		output[i][0]='X';

	selectlevel();//选择关卡界面，其中调用Play函数
	COORD coord = { 0 };
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置复原
	system("pause");
	return 0;
}
void selectlevel()
{
	COORD coord = { 0 };		//光标结构体定义
	
	ifstream fin;
	fin.open("in.txt");
	int n;
	fin >> n;
	fin.close();
	int m=10005;
	while (m > n)
	{
		coord.X = 30;
		coord.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("您当前已通关至：第%d关", n);
		coord.X = 30;
		coord.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("你现在可以选择的关卡有：第");
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", i);
		}
		printf("关");
		coord.X = 30;
		coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("请从键盘输入你想玩的关卡");
		cin >> m;
		if (m > n)
		{
			coord.X = 30;
			coord.Y = 8;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			cout << "抱歉，您不能跳关,请重新选择关卡";
		}
		coord.X = 30;
		coord.Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		system("pause");
		system("cls");
	}

	if (m == 1) Play1();
	if (m == 2) Play2();
	if (m == 3) Play3();
	//if (m == 4) Play4();
	return;
}

