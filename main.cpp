#include "base.h"
//#define _CRT_SECUER_NO_WARNINGS
//机器人位置初始化
int level;
bool flag;//标记是否出错
int emptynum;//当前空地数
int speed = 100;//调整机器人移动速度，全局变量 
bool inboxnon = 0;

int nowx = 20, nowy = 4;//全局变量记录当前机器人的左上角位置,初始值为20,4
int inputnum, outputnum, emptyputnum;

bool isnowwood;
char nowwood[5];

char input[30][5];//记录输入序列
char output[30][5];//记录当下输出传送带上的值
char emptyput[30][5];//记录空地上的值

char s1[100];
bool mark[1000];

Instruction instruction[1002];

ROBOT robot;

WOOD inwood, outwood, emptywood, awood;
//inwood输入传送带，outwood输出传送带，emptywood空地,awood当前搬运

int score = 0;//分数

int main()
{
	/*for (int i = 1; i <= Height; i++)//看看wide调多大
	{
		for (int j = 1; j <= Wide; j++)
			cout << "#";
		cout << endl;
	}*/
	

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
	overagain();

	COORD coord = { 0 };		//光标结构体定义

	ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open())cout << "Error";
	fin >> level;
	fin.close();
	int m = 10005;
	
	while (m > level)
	{
		printlevel();
		coord.X = 30;
		coord.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		if (level == 5) cout << "您已经通过所有关卡！";
		else cout << "您当前已通关至：第 " << level << " 关 ";//printf("您当前已通关至：第 % d 关 ", n);
		coord.X = 30;
		coord.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("你现在可以选择的关卡有：第 ");
		for (int i = 1; i <= level && i<=4; i++)
		{
			printf("%d ", i);
		}
		printf(" 关 ");
		coord.X = 30;
		coord.Y = 14;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("请从键盘输入你想玩的关卡 ");

		char nnn[10000];
		cin.getline(nnn, 10000);
		m = tonumstruction(nnn);
		
		if (m == -1)
		{
			setposition(30, 16);
			cout << "格式错误，请重新输入";
			setposition(30, 17);
			system("pause");
			system("cls");
			selectlevel();
		}
		if (m != 1 && m != 2 && m != 3 && m != 4)
		{
			setposition(30, 16);
			cout << "不存在此关卡，请重新输入";
			setposition(30, 17);
			system("pause");
			system("cls");
			selectlevel();
		}

		if (m > level)
		{
			coord.X = 30;
			coord.Y = 16;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			cout << "第 " << m << " 关尚未解锁，请重新选择关卡";
		}

		coord.X = 30;
		coord.Y = 17;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		system("pause");
		system("cls");

	}

	if (m == 1) Play1();
	if (m == 2) Play2();
	if (m == 3) Play3();
	if (m == 4) Play4();
	return;
}

//打印关卡的四个方框
void printlevel()
{
	for (int i = 1; i < 6; i++)
	{
		setposition(35 + i, 5); printf("_");
		setposition(45 + i, 5); printf("_");
		setposition(55 + i, 5); printf("_");
		setposition(65 + i, 5); printf("_");
		setposition(35 + i, 8); printf("_");
		setposition(45 + i, 8); printf("_");
		setposition(55 + i, 8); printf("_");
		setposition(65 + i, 8); printf("_");
	}
	for (int j = 0; j < 3; j++)
	{
		setposition(35, 6 + j); printf("|");
		setposition(45, 6 + j); printf("|");
		setposition(55, 6 + j); printf("|");
		setposition(65, 6 + j); printf("|");
		setposition(41, 6 + j); printf("|");
		setposition(51, 6 + j); printf("|");
		setposition(61, 6 + j); printf("|");
		setposition(71, 6 + j); printf("|");
	}
	for (int i = 0; i < level && i<4; i++)
	{
		setposition(38 + i * 10, 7);
		cout << i + 1;
	}
	for (int i = level; i < 4; i++)
	{
		setposition(38 + i * 10, 7); printf("X");
	}
}

//重新返回关卡选择界面时，把一些变量设置回初始值 (在selectlevel的最开始调用一次）
void overagain()
{
	for (int i = 0; i < 20; i++)
		input[i][0] = 'X';
	for (int i = 0; i < 20; i++)
		output[i][0] = 'X';

	speed = 100;
	inboxnon = 0;
	nowx = 20;   nowy = 4;
	flag = 0;

	for (int i = 0; i < 1000; i++)
		mark[i] = 0;
}
