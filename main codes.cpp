#include "initialization.h"
#include "function.h"
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
	strcpy(input[0],"1");
	strcpy(input[1],"2");
	cin >> n;
	printf("请按行输入你的指令:");
	for (int i = 1; i <= n; i++)
	{
		cin >> instruction[i].s;
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else cin >> instruction[i].num;
	}
	system("cls");
	initUI1();
	COORD coord = { 0 };		//光标结构体定义
	for (int i = 1; i <= n; i++)
	{
		coord.X = 59;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		coord.X = 58;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar('>');//将>号指向当下正在执行的命令
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		if(inboxnon) Judge1();
		//每条指令执行完后，箭头下移
		coord.X = 58;
		coord.Y = 2 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}
	}
	deletenowwood();
	Judge1();
}
void Play2()
{
	/*	输入序列：3,9,5,1,-2,-2,9,-9
		目标输出序列：-6,6,4,-4,0,0,18,-18
		可用空地数：3
		可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI2();
	setposition(0,19);//设置光标位置
	printf("输入序列：3,9,5,1,-2,-2,9,-9 \n目标输出序列：-6,6,4,-4,0,0,18,-18 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
	inputnum = 8;
	outputnum = 0;
	emptynum = 3;
	strcpy(input[0] ,"3");
	strcpy(input[1] ,"9");
	strcpy(input[2] ,"5");
	strcpy(input[3] , "1");
	strcpy(input[4] ,"-2");
	strcpy(input[5] ,"-2");
	strcpy(input[6] , "9");
	strcpy(input[7] , "-9");
	//n记录指令数； 
	cin >> n;
	printf("请按行输入你的指令:");
	for (int i = 1; i <= n; i++)
	{ 
		scanf("%s", instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else if(notinstruction(instruction[i].s))
		{
			gets(s1);
			mark[i]=1;
			continue;
		} 
		gets(s1);
		instruction[i].num=tonumstruction(s1);
		if(instruction[i].num==-1)
		{
			mark[i]=1;
		}
	}
	system("cls");
	initUI2();
	for (int i = 1; i <= n; i++)
	{
		if(i<=20)
			setposition(59,2+i);	//设置光标位置
		else if(i>20&&i<=40) setposition(79,2+i-20);
		else if(i>40&&i<=60) setposition(99,2+i-40);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi=i;
		if(mark[i]) 
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}	
		if(i<=20)
			setposition(58,2+i);	//设置光标位置
		else if(i>20&&i<=40) setposition(78,2+i-20);
		else if(i>40&&i<=60) setposition(98,2+i-40);
		putchar('>');//将>号指向当下正在执行的命令
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if(strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num,&i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num,&i);
		if(inboxnon) Judge2();
		//每条指令执行完后，箭头下移
		if(nowi<=20)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>20&&nowi<=40) setposition(78,2+nowi-20);
		else if(nowi>40&&nowi<=60) setposition(98,2+nowi-40);
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}
	}
	deletenowwood();
	Judge2();
}
void Play3()
{
	/*	输入序列：6,2,7,7,-9,3,-3,-3
		目标输出序列：7,-3
		可用空地数：3
		可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI3();
	setposition(0,19);//设置光标位置
	printf("输入序列：6,2,7,7,-9,3,-3,-3 \n目标输出序列：7,-3 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
	inputnum = 8;
	outputnum = 0;
	emptynum = 3;
	strcpy(input[0] ,"6");
	strcpy(input[1] ,"2");
	strcpy(input[2] ,"7");
	strcpy(input[3] , "7");
	strcpy(input[4] ,"-9");
	strcpy(input[5] ,"3");
	strcpy(input[6] , "-3");
	strcpy(input[7] , "-3");
	//n记录指令数； 
	cin >> n;
	printf("请按行输入你的指令:");
	for (int i = 1; i <= n; i++)
	{ 
		scanf("%s", instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else if(notinstruction(instruction[i].s))
		{
			gets(s1);
			mark[i]=1;
			continue;
		}
		gets(s1);
		instruction[i].num=tonumstruction(s1);
		if(instruction[i].num==-1)
		{
			mark[i]=1;
		}
	}
	system("cls");
	initUI3();
	for (int i = 1; i <= n; i++)
	{
		if(i<=25)
			setposition(59,2+i);	//设置光标位置
		else if(i>25&&i<=50) setposition(79,2+i-25);
		else if(i>50&&i<=75) setposition(99,2+i-50);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi=i;
		if(mark[i])
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}	
		if(nowi<=25)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>25&&nowi<=50) setposition(78,2+nowi-25);
		else if(nowi>50&&nowi<=75) setposition(98,2+nowi-50);
		putchar('>');//将>号指向当下正在执行的命令
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if(strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num,&i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num,&i);
		if(inboxnon) Judge3();
		//每条指令执行完后，箭头下移
		if(nowi<=25)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>25&&nowi<=50) setposition(78,2+nowi-25);
		else if(nowi>50&&nowi<=75) setposition(98,2+nowi-50);
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}
	}
	deletenowwood();
	Judge3();
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
	for (int i = 0; i < 6; i++)
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
	setposition(7, 2);//设置光标位置
	putchar('3');
	setposition(7,5);//设置光标位置
	putchar('9');
	setposition(7, 8);
	putchar('5');
	setposition(7, 11);
	putchar('1');
	setposition(6, 14);
	cout<<-2;
	setposition(6, 17);
	cout<<-2;
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
	setposition(7,5);//设置光标位置
	putchar('2');
	setposition(7, 8);
	putchar('7');
	setposition(7, 11);
	putchar('7');
	setposition(6, 14);
	cout<<-9;
	setposition(7, 17);
	cout<<3;
	//画出emptywood空地
	PrintEmptywood(3);
	//画outwood传送带
	PrintOutwood();
	//画竖线
	PrintLine();
	//命令行界面
	PrintCode();
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
void PrintWood(int x,int y,string number)
{
	for(int i=0;i<3;i++)
		for (int j = 0; j < 5; j++)
		{
			setposition(x+j,y+i);	//设置光标位置
			if ((j == 0 || j == 4) && (i == 0 || i == 2)) putchar('+');
			else if (i == 0 || i == 2) putchar('-');
			else if (j == 0 || j == 4) putchar('|');
		}
	Printnum(x+2,y+1,number); 
	//isnowwood = true;
	return;
}
//指令行界面
//X=57,Y=1

void adjustspeed()//在toleft和right的时候判断就行 
{
	if(_kbhit())//判断用户是否按按键，不阻塞读入 
	{
		char ch=getch();
		if(ch=='1') speed=150;
		if(ch=='2') speed=100;
		if(ch=='3') speed=75;
		if(ch=='4') speed=25;
		if(ch=='5') speed=5;
	} 
}

void Printnum(int x,int y,string s)//分别处理输出长度1,2,3的情况 
{
	int len=s.length();
	setposition(x-1,y);
	if(s[0]=='-')
	{
		cout<<s;
		if(len==2) putchar(' ');
	}
	else
	{
		putchar(' ');
		cout<<s;
		if(len==1) putchar(' ');
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
			coord.X = nowx +1+ j;
			coord.Y = nowy -3+ i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
			putchar(' ');
		}
	return;
}
void movetoleft()
{
	Hide(); //隐藏光标
	adjustspeed();//调速 
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
	initrobot(nowx , nowy);
	PrintRobot();
	Sleep(speed);
}
void Judge1()//判断游戏第一关胜负
{ 
	COORD coord;
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 2 && output[0][0] == '2' && output[1][0] == '1')
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin>>nn;
		fin.close();
		if(nn<2)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 2;
		}
	}
	else cout << "Fail";
	exit(0);
}
void Judge2()//判断游戏第二关胜负
{
	setposition(0,29);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 8 && (strcmp(output[0],"-18")==0) && (strcmp(output[1],"18")==0)&&(strcmp(output[2],"0")==0)&&
	(strcmp(output[3],"0")==0)&&(strcmp(output[4],"-4")==0)&&(strcmp(output[5],"4")==0)
	&&(strcmp(output[6],"6")==0)&&(strcmp(output[7],"-6")==0))
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin>>nn;
		fin.close();
		if(nn<3)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 3;
		}
	}
	else cout << "Fail";
	exit(0);
}
void Judge3()//判断游戏第三关胜负
{
	setposition(0,29);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 2 && (strcmp(output[0],"-3")==0) && (strcmp(output[1],"7")==0))
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin>>nn;
		fin.close();
		if(nn<4)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 4;
		}
	}
	else cout << "Fail";
	exit(0);
}
void setposition(int x,int y)//设置光标位置
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool notinstruction(char s[])
{
	if(strcmp(s,"inbox")!=0&&strcmp(s,"outbox")!=0&&strcmp(s,"add")!=0&&strcmp(s,"sub")!=0
	&&strcmp(s,"copyto")!=0&&strcmp(s,"copyfrom")!=0&&strcmp(s,"jump")!=0&&strcmp(s,"jumpifzero")!=0)
	{
		return 1;
	}
	else return 0;
}
void Hide()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=sizeof(cci);
	cci.bVisible=false;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
	return ;
}
