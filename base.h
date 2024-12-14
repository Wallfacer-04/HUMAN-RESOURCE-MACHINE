#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<string>
using namespace std;

#define HEIGHT 50
#define WIDE 120
#define MAXN WIDE*HEIGHT//机器人最大占多少个位置

//typedef struct _COORD
//{
//	int X;
//	int Y;
//}COORD;
extern int level;
extern bool flag;//标记是否出错
extern int emptynum;//当前空地数
extern int speed ;//调整机器人移动速度，全局变量 
extern bool inboxnon;

extern int nowx , nowy;//全局变量记录当前机器人的左上角位置,初始值为20,4
extern int inputnum, outputnum, emptyputnum;

extern bool isnowwood;
extern char nowwood[5];

extern char input[30][5];//记录输入序列
extern char output[30][5];//记录当下输出传送带上的值
extern char emptyput[30][5];//记录空地上的值

extern char s1[100];
extern bool mark[1000];

struct Instruction
{
	char s[10000];
	char appendix[10000];
	int num;
};
extern Instruction instruction[1002];

struct DIRECT//坐标
{
	int X, Y;//坐标方式指定每个点位置
};

struct ROBOT
{
	DIRECT body[MAXN];//存储机器人加货物
	int size;//指定机器人加上货物一共的大小
};
extern ROBOT robot;

struct WOOD
{
	DIRECT body[MAXN];//存储机器人加货物
	int size;//指定货物的大小
};
extern WOOD inwood, outwood, emptywood, awood;
//inwood输入传送带，outwood输出传送带，emptywood空地,awood当前搬运

extern int score;//分数
//函数声明
void selectlevel();//选择关卡
void printlevel();
void Play1();
void Play2();
void Play3();
void Play4();
void initrobot(int, int);
void initwood();
void initUI1();
void initUI2();
void initUI3();
void initUI4();
void PrintRobot();
void deleterobot();
void PrintWood(int, int, string);
void PrintInwood();
void PrintOutwood();
void PrintEmptywood(int);
void PrintIN();
void PrintOUT();
void Print(int, int, char);
void PrintLine();	//画出竖线
void PrintCode();	//右侧CODE命令执行界面
void movetoleft();
void movetoright();
void deletenowwood();

void initwood_4();
void PrintInwood_4();
void PrintOutwood_4();
void PrintLine_4();
void PrintEmptywood_4(int);
void PrintIN_4();
void PrintOUT_4();
void PrintCode_4();

void Judge1();
void Judge2();
void Judge3();
void Judge4();

void setposition(int, int);
void Hide();
int tonum(char[]);
void tostring(char[], int);
void Printnum(int, int, string);
void adjustspeed();
bool notinstruction(char[]);
int tonumstruction(char[]);

void inbox();
void outbox();
void add(int);
void sub(int);
void copyto(int);
void copyfrom(int);
void jump(int, int*);
void jumpifzero(int, int*);
void inbox_4();
void outbox_4();

void overagain();
