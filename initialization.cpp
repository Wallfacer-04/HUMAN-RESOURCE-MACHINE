#include "initialization.h"

//机器人位置初始化

int main()
{
	/*for (int i = 1; i <= Height; i++)//看看wide调多大
	{
		for (int j = 1; j <= Wide; j++)
			cout << "#";
		cout << endl;
	}*/
	memset(input, 'X', sizeof(input));
	memset(output, 'X', sizeof(output));

	initrank();//选择关卡界面，其中调用Play函数
	COORD coord = { 0 };
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置复原
	system("pause");
	return 0;
}
void Play1()
{
	/*	输入序列：1, 2
		目标输出序列：1, 2
		可用空地数：0
		可用指令集：inbox, outbox*/
	initUI1();
	printf("输入序列：1, 2 \n目标输出序列：1, 2 \n可用空地数：0 \n 可用指令集：inbox, outbox\n请输入你的指令数：\n");
	inputnum = 2;
	outputnum = 0;
	input[0] = '1', input[1] = '2';
	int n;
	cin >> n;
	printf("请按行输入你的指令:");
	for (int i = 0; i < n; i++)
	{
		cin >> instruction[i].s;
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else cin >> instruction[i].num;
	}
	system("cls");
	initUI1();
	COORD coord = { 0 };		//光标结构体定义
	for (int i = 0; i < n; i++)
	{
		coord.X = 59;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 0; i < n; i++)
	{
		coord.X = 58;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar('>');//将>号指向当下正在执行的命令
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		//每条指令执行完后，箭头下移
		coord.X = 58;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i + 1;
			return;
		}
	}
	deletenowwood();
	Judge1();
}
void Play2()
{

}
void Play3()
{

}

void initrank()
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
	return;
}

//初始化robot、wood的变量信息
// 
//robot左上角坐标：x=20,y=4
void initrobot(int k,int p)
{
	for (int i = 1; i <= 5; i++)
	{
		robot.body[i].X = k + i;//头上，5个-
		robot.body[i].Y =  p;
	}
	robot.body[6].X = k+1;//头左，|
	robot.body[6].Y = p + 1;
	robot.body[7].X = k + 6-1;//头右，|
	robot.body[7].Y =  p + 1;
	for (int i = 8; i <= 12; i++)
	{
		robot.body[i].X = k + (i - 7);//头下，5个-
		robot.body[i].Y =  p + 2;
	}
	robot.body[13].X = k + 2;//左手，/
	robot.body[13].Y =  p + 3;
	robot.body[14].X = k + 4;//右手，\

	robot.body[14].Y =  p + 3;
	robot.body[15].X = k + 1;//左手，/
	robot.body[15].Y =  p + 4;
	robot.body[16].X = k + 5;//右手，\

	robot.body[16].Y =  p + 4;
	for (int i = 17; i <= 21; i++)
	{
		robot.body[i].X = k + (i - 16);//横着，5个-
		robot.body[i].Y =  p + 5;
	}
	robot.body[22].X = k + 2;//脚|
	robot.body[22].Y = p + 6;
	robot.body[23].X = k + 4;//脚|
	robot.body[23].Y =  p + 6;
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
		inwood.body[i].Y = 1+3*i;
	}//初始化inwood输入传送带  x=5,y=1
	for (int i = 0; i < 4;i++)
	{
		emptywood.body[i].X = 15+5*i;
		emptywood.body[i].Y = 11;
	}//初始化emptywood空地  x=15 y=11
	for (int i = 0; i < 4; i++)
	{
		outwood.body[i].X = 40;
		outwood.body[i].Y = 1 + 3 * i;
	}//初始化outwood传送带 x=40 y=1

	return;
}

//初始化界面控界,画出机器人，inwood，outwood，emptywood
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
	//画emptywood空地
	PrintEmptywood();
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();

	//将光标移动到最下方防止干扰
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 0;
	coord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
}
void initUI3()
{
	initrobot(20, 4);
	initwood();

	//画机器人
	PrintRobot();
	//画inwood传送带
	PrintInwood();
	//画emptywood空地
	PrintEmptywood();
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();

	//将光标移动到最下方防止干扰
	COORD coord = { 0 };		//光标结构体定义
	coord.X = 0;
	coord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
}
//每次使用之前先initrobot（）
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
		PrintWood(inwood.body[i].X, inwood.body[i].Y, 'X');
	}
}
//inwood   x=5,y=1
void PrintEmptywood()
{
	//画emptywood传送带
	for (int i = 0; i < 4; i++)
	{
		PrintWood(emptywood.body[i].X, emptywood.body[i].Y, 'X');
		Print(emptywood.body[i].X + 2, emptywood.body[i].Y + 3, i + 48);
	}
	return;
}
//emptywood   x=15,y=11
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
	isnowwood = true;
	return;
}
//指令行界面
//X=57,Y=1
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
			coord.X = nowx +1+ j;
			coord.Y = nowy -3+ i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			putchar(' ');
		}
	return;
}
void movetoleft()
{
	initrobot(nowx,nowy);
	deleterobot();
	deletenowwood();
	if (isnowwood)
	{
		PrintWood(nowx-1 + 1, nowy - 3, nowwood);
	}
	nowx--;
	initrobot(nowx, nowy);
	PrintRobot();
	Sleep(100);
}
void movetoright()
{
	initrobot(nowx, nowy);
	deleterobot();
	deletenowwood();
	if (isnowwood)
	{
		PrintWood(nowx + 1 + 1, nowy - 3, nowwood);
	}
	nowx++;
	initrobot(nowx , nowy);
	PrintRobot();
	Sleep(100);
}
void Judge1()//判断游戏第一关胜负
{ 
	COORD coord;
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 2 && output[0] == '2' && output[1] == '1') cout << "Success";
	else cout << "Fail";


}

void inbox()
{
	while (nowx > 10)//贴到左边
	{
		movetoleft();
		//其中包含Sleep(100);
	}
	if (inputnum==0)//结束游戏
	{
		Judge1();
		return;
	}
	//拿起木块
	isnowwood = true;
	nowwood = input[0];
	PrintWood(nowx + 1, nowy - 3, input[0]);
	//传送带动
	COORD coord = { 0 };		//光标结构体定义
	for (int i = 0; i < inputnum; i++)
	{
		coord.X = inwood.body[i].X + 2;
		coord.Y = inwood.body[i].Y + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		input[i] = input[i + 1];
		putchar(input[i]);
	}
	inputnum--;
	coord.X = inwood.body[inputnum].X + 2;
	coord.Y = inwood.body[inputnum].Y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar(input[inputnum + 1]);
}
void outbox()
{
	while (nowx<33)
	{
		movetoright();
		//其中包含Sleep(100)
	}
	if (isnowwood==false)//错误情况
	{
		system("cls");
		COORD coord;
		coord.X = 30;
		coord.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		flag = 1;//标志出错
		return;
	}
	//放下木块
	isnowwood = false;
	outputnum++;
	//传送带动
	COORD coord = { 0 };		//光标结构体定义
	for (int i = outputnum; i > 0; i--)
	{
		output[i] = output[i - 1];
		coord.X = outwood.body[i].X + 2;
		coord.Y = outwood.body[i].Y + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar(output[i]);
	}
	output[0] = nowwood;
	coord.X = outwood.body[0].X + 2;
	coord.Y = outwood.body[0].Y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar(output[0]);
}
