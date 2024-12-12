//#pragma once
//定义8种指令集 
#include "base.h" 
void inbox()
{
	while (nowx > 10)//贴到左边
	{
		movetoleft();
		//其中包含Sleep(25);
	}
	if (inputnum == 0)//结束游戏
	{
		inboxnon=1;
		return;
	}
	//拿起木块
	isnowwood = true;
	strcpy(nowwood,input[0]);
	PrintWood(nowx + 1, nowy - 3, input[0]);
	//传送带动
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
		//其中包含Sleep(25)
	}
	if (isnowwood == false)//错误情况
	{
		system("cls");
		flag = 1;//标志出错
		return;
	}
	//放下木块
	isnowwood = false;
	outputnum++;
	//传送带动
	for (int i = outputnum; i > 0; i--)
	{
		strcpy(output[i],output[i - 1]);
		if(i<6)
			Printnum(outwood.body[i].X + 2,outwood.body[i].Y + 1,output[i]);//格式化输出 
	}
	strcpy(output[0] , nowwood);
	Printnum(outwood.body[0].X + 2,outwood.body[0].Y + 1,output[0]);//格式化输出 
}
void add(int x)
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//其中包含Sleep(25)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//其中包含Sleep(25);
	}
	tostring(nowwood,tonum(nowwood)+tonum(emptyput[x]));
	Printnum(nowx + 3,nowy - 2,nowwood);//到当前货物的正中心输出
}
void sub(int x)//与add相比只把+改成了- 
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//其中包含Sleep(25)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//其中包含Sleep(25);
	}
	tostring(nowwood,tonum(nowwood)-tonum(emptyput[x]));
	Printnum(nowx + 3,nowy - 2,nowwood);//到当前货物的正中心输出
}
void copyto(int x)
{
	if ((isnowwood == false||x>=emptynum))//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//其中包含Sleep(speed)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//其中包含Sleep(speed);
	}
	//放下物块 
	isnowwood=false;
	deletenowwood();
	strcpy(emptyput[x] ,nowwood);
	
	Printnum(emptywood.body[x].X + 2,emptywood.body[x].Y + 1,emptyput[x]) ;//格式化输出;
}
void copyfrom(int x)
{
	if (x>=emptynum||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	while (nowx < 14+5*x)
	{
		movetoright();
		//其中包含Sleep(100)
	}
	while (nowx > 14 + 5 * x)
	{
		movetoleft();
		//其中包含Sleep(100);
	}
	//不管有没有，生成物块，isnowwood置为真 
	strcpy(nowwood,emptyput[x]);
	PrintWood(nowx + 1, nowy - 3, nowwood);
	isnowwood=1;
}
void jump(int x,int *p)
{
	if (x>n)//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	*p=x-1;//回到x上一个位置循环 
}
void jumpifzero(int x,int *p)
{
	if (x>n||isnowwood==false)//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	if(nowwood[0]=='0')
		*p=x-1;
}

