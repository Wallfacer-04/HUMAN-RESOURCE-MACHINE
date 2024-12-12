//#pragma once
//��ʼ������ 
#include "base.h"
//��ʼ������ؽ�,�趨������λ�ã�inwood��outwood��emptywood
void initUI1()
{
	initrobot(20, 4);
	initwood();

	//��������
	PrintRobot();
	//��inwood���ʹ�
	PrintInwood();
	COORD coord = { 0 };		//���ṹ�嶨��
	coord.X = 7;
	coord.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
	putchar('1');
	coord.X = 7;
	coord.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
	putchar('2');
	//��emptywood�յ�
	//PrintEmptywood();
	//��outwood���ʹ�
	PrintOutwood();
	//������
	PrintLine();
	//�����н���
	PrintCode();
	//������ƶ������·���ֹ����
	coord.X = 0;
	coord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
}
void initUI2()
{
	initrobot(20, 4);
	initwood();

	//��������
	PrintRobot();
	//��inwood���ʹ�
	PrintInwood();
	setposition(7, 2);//���ù��λ��
	putchar('3');
	setposition(7,5);//���ù��λ��
	putchar('9');
	setposition(7, 8);
	putchar('5');
	setposition(7, 11);
	putchar('1');
	setposition(6, 14);
	cout<<-2;
	setposition(6, 17);
	cout<<-2;
	//����emptywood�յ�
	PrintEmptywood(3);
	//��outwood���ʹ�
	PrintOutwood();
	//������
	PrintLine();
	//�����н���
	PrintCode();
}
void initUI3()
{
	initrobot(20, 4);
	initwood();

	//��������
	PrintRobot();
	//��inwood���ʹ�
	PrintInwood();
	setposition(7, 2);//���ù��λ��
	putchar('6');
	setposition(7,5);//���ù��λ��
	putchar('2');
	setposition(7, 8);
	putchar('7');
	setposition(7, 11);
	putchar('7');
	setposition(6, 14);
	cout<<-9;
	setposition(7, 17);
	cout<<3;
	//����emptywood�յ�
	PrintEmptywood(3);
	//��outwood���ʹ�
	PrintOutwood();
	//������
	PrintLine();
	//�����н���
	PrintCode();
}

//��ʼ��robot��wood�ı�����Ϣ
// 
//robot���Ͻ����꣺x=20,y=4
void initrobot(int k,int p)
{
	for (int i = 1; i <= 5; i++)
	{
		robot.body[i].X = k + i;//ͷ�ϣ�5��-
		robot.body[i].Y =  p;
	}
	robot.body[6].X = k+1;//ͷ��|
	robot.body[6].Y = p + 1;
	robot.body[7].X = k + 6-1;//ͷ�ң�|
	robot.body[7].Y =  p + 1;
	for (int i = 8; i <= 12; i++)
	{
		robot.body[i].X = k + (i - 7);//ͷ�£�5��-
		robot.body[i].Y =  p + 2;
	}
	robot.body[13].X = k + 2;//���֣�/
	robot.body[13].Y =  p + 3;
	robot.body[14].X = k + 4;//���֣�\

	robot.body[14].Y =  p + 3;
	robot.body[15].X = k + 1;//���֣�/
	robot.body[15].Y =  p + 4;
	robot.body[16].X = k + 5;//���֣�\

	robot.body[16].Y =  p + 4;
	for (int i = 17; i <= 21; i++)
	{
		robot.body[i].X = k + (i - 16);//���ţ�5��-
		robot.body[i].Y =  p + 5;
	}
	robot.body[22].X = k + 2;//��|
	robot.body[22].Y = p + 6;
	robot.body[23].X = k + 4;//��|
	robot.body[23].Y =  p + 6;
	robot.body[1].X = k + 2;//�۾�
	robot.body[1].Y = p + 1;
	robot.body[5].X = k + 4;//�۾�
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
	}//��ʼ��inwood���봫�ʹ�  x=5,y=1
	for (int i = 0; i < 4;i++)
	{
		emptywood.body[i].X = 15+5*i;
		emptywood.body[i].Y = 11;
	}//��ʼ��emptywood�յ�  x=15 y=11
	for (int i = 0; i < 6; i++)
	{
		outwood.body[i].X = 40;
		outwood.body[i].Y = 1 + 3 * i;
	}//��ʼ��outwood���ʹ� x=40 y=1

	return;
}

