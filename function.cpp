//#pragma once
//����8��ָ� 
#include "base.h" 
void inbox()
{
	while (nowx > 10)//�������
	{
		movetoleft();
		//���а���Sleep(25);
	}
	if (inputnum == 0)//������Ϸ
	{
		inboxnon=1;
		return;
	}
	//����ľ��
	isnowwood = true;
	strcpy(nowwood,input[0]);
	PrintWood(nowx + 1, nowy - 3, input[0]);
	//���ʹ���
	for (int i = 0; i < inputnum; i++)
	{
		strcpy(input[i], input[i + 1]);
		if(i<6) 
		{
			Printnum(inwood.body[i].X + 2,inwood.body[i].Y + 1,input[i]);
		}
	}
	inputnum--;
}
void outbox()
{
	while (nowx < 33)
	{
		movetoright();
		//���а���Sleep(25)
	}
	if (isnowwood == false)//�������
	{
		system("cls");
		flag = 1;//��־����
		return;
	}
	//����ľ��
	isnowwood = false;
	outputnum++;
	//���ʹ���
	for (int i = outputnum; i > 0; i--)
	{
		strcpy(output[i],output[i - 1]);
		if(i<6)
			Printnum(outwood.body[i].X + 2,outwood.body[i].Y + 1,output[i]);//��ʽ����� 
	}
	strcpy(output[0] , nowwood);
	Printnum(outwood.body[0].X + 2,outwood.body[0].Y + 1,output[0]);//��ʽ����� 
}
void add(int x)
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//���а���Sleep(25)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//���а���Sleep(25);
	}
	tostring(nowwood,tonum(nowwood)+tonum(emptyput[x]));
	Printnum(nowx + 3,nowy - 2,nowwood);//����ǰ��������������
}
void sub(int x)//��add���ֻ��+�ĳ���- 
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//���а���Sleep(25)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//���а���Sleep(25);
	}
	tostring(nowwood,tonum(nowwood)-tonum(emptyput[x]));
	Printnum(nowx + 3,nowy - 2,nowwood);//����ǰ��������������
}
void copyto(int x)
{
	if ((isnowwood == false||x>=emptynum))//�������
	{
		flag = 1;//��־����
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//���а���Sleep(speed)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//���а���Sleep(speed);
	}
	//������� 
	isnowwood=false;
	deletenowwood();
	strcpy(emptyput[x] ,nowwood);
	
	Printnum(emptywood.body[x].X + 2,emptywood.body[x].Y + 1,emptyput[x]) ;//��ʽ�����;
}
void copyfrom(int x)
{
	if (x>=emptynum||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//���а���Sleep(100)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//���а���Sleep(100);
	}
	//������û�У�������飬isnowwood��Ϊ�� 
	strcpy(nowwood,emptyput[x]);
	PrintWood(nowx + 1, nowy - 3, nowwood);
	isnowwood=1;
}
void jump(int x,int *p)
{
	if (x>n)//�������
	{
		flag = 1;//��־����
		return;
	}
	*p=x-1;//�ص�x��һ��λ��ѭ�� 
}
void jumpifzero(int x,int *p)
{
	if (x>n||isnowwood==false)//�������
	{
		flag = 1;//��־����
		return;
	}
	if(nowwood[0]=='0')
		*p=x-1;
}

