//ͷ�ļ����ں����������뺯������ 
#pragma once

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
#define MAXN WIDE*HEIGHT//���������ռ���ٸ�λ��

//typedef struct _COORD
//{
//	int X;
//	int Y;
//}COORD;
int n; 
bool flag;//����Ƿ����
int emptynum;//��ǰ�յ���
int speed=100;//�����������ƶ��ٶȣ�ȫ�ֱ��� 
bool inboxnon=0;

int nowx=20, nowy=4;//ȫ�ֱ�����¼��ǰ�����˵����Ͻ�λ��,��ʼֵΪ20,4
int inputnum,outputnum,emptyputnum;

bool isnowwood;
char nowwood[5];

char input[30][5];//��¼��������
char output[30][5];//��¼����������ʹ��ϵ�ֵ
char emptyput[30][5];//��¼�յ��ϵ�ֵ

char s1[100];
bool mark[1000];

struct Instruction 
{
	char s[10];
	int num;
}instruction[1002];

struct DIRECT//����
{
	int X, Y;//���귽ʽָ��ÿ����λ��
};

struct ROBOT
{
	DIRECT body[MAXN];//�洢�����˼ӻ���
	int size;//ָ�������˼��ϻ���һ���Ĵ�С
}robot;

struct WOOD
{
	DIRECT body[MAXN];//�洢�����˼ӻ���
	int size;//ָ������Ĵ�С
}inwood,outwood,emptywood,awood;
//inwood���봫�ʹ���outwood������ʹ���emptywood�յ�,awood��ǰ����

int score = 0;//����
//��������
void selectlevel();//ѡ��ؿ�
void Play1();
void Play2();
void Play3();
void Play4();
void initrobot(int,int);
void initwood();
void initUI1();
void initUI2();
void initUI3();
void PrintRobot();
void deleterobot();
void PrintWood(int, int, string);
void PrintInwood();
void PrintOutwood();
void PrintEmptywood(int);
void PrintIN();
void PrintOUT();
void Print(int, int, char);
void PrintLine();	//��������
void PrintCode();	//�Ҳ�CODE����ִ�н���
void movetoleft();
void movetoright();
void deletenowwood();

void Judge1();
void Judge2();
void Judge3();

void setposition(int, int);
void Hide();
int tonum(char []);
void tostring(char [],int);
void Printnum(int,int,string);
void adjustspeed(); 
bool notinstruction(char []);
int tonumstruction(char []);

void inbox();
void outbox();
void add(int);
void sub(int);
void copyto(int);
void copyfrom(int);
void jump(int,int*);
void jumpifzero(int,int*);

