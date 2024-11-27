#pragma once

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include "instructs.h"
using namespace std;

#define HEIGHT 50
#define WIDE 120
#define MAXN WIDE*HEIGHT//机器人最大占多少个位置

//typedef struct _COORD
//{
//	int X;
//	int Y;
//}COORD;
bool flag;//标记是否出错

int nowx = 20, nowy = 4;//全局变量记录当前机器人的左上角位置,初始值为20,4
int inputnum, outputnum;

bool isnowwood;
int nowwood;

//char input[20];//记录输入序列
//char output[20];  

struct coordinate_of_current
{
	int X, Y;
}current_coord;     //对当前木块左上角的位置做一个记录

struct Instruction
{
	char s[10];
	int num;
}instruction[102];

struct DIRECT//坐标
{
	int X, Y;//坐标方式指定每个点位置
};

struct ROBOT
{
	DIRECT body[MAXN];//存储机器人加货物
	int size;//指定机器人加上货物一共的大小
}robot;

struct WOOD
{
	DIRECT body[MAXN];//存储机器人加货物
	int size;//指定机器人加上货物一共的大小
}inwood, outwood, emptywood, awood;
//inwood输入传送带，outwood输出传送带，emptywood空地,awood当前搬运

int score = 0;//分数
//函数声明
void initrank();//选择关卡
void initrobot(int, int);
void initwood();
void initUI1();
void initUI2();
void initUI3();
void PrintRobot();
void deleterobot();
void PrintWood(int, int, bool, int);
void PrintInwood();
void PrintOutwood();
void PrintEmptywood();
void PrintIN();
void PrintOUT();
void Print(int, int, char);
void PrintLine();	//画出竖线
void PrintCode();	//右侧CODE命令执行界面
void movetoleft();
void movetoright();
void deletenowwood();

void Play1();

void Judge1();

//void inbox();
//void outbox();
