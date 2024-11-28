#include "initialization_v2.h"
#include "instructs.h"
using namespace std;



void inbox(void)
{
    current.num=input[0].num;  
    current.filled=1;         //拿起input.num上第一个元素

    it_input=input.begin();
    input.erase(it_input);   //删除input.num的第一个元素

    //以上让机器人移动到输入传送带旁
    while (nowx > 10)//贴到左边
	{
		movetoleft();
		//其中包含Sleep(100);
	}    

    //以下更新输入传送带 并显示
    COORD coord = { 0 };
    int len_inwood=distance(input.begin(),input.end());  //这是inwood中有元素的木块的个数
    for (int i = 0; i < len_inwood ; i++)
	{
		coord.X = inwood.body[i].X + 2;
		coord.Y = inwood.body[i].Y + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		//input[i] = input[i + 1];   这里删掉，因为前面用input.erase已经删除了第0个元素并让input矢量整体前移
		printf("%d",input[i].num);
	}

    //以下打印机器人手中的wood
    PrintWood(nowx+1,nowy-3, 1 , current.num);


    bool is_empty=1;
    for(int i=0;i<10;i++)
    {
        if(input[i].filled==1)
        {
            is_empty=0;
            break;
        }
    }
    if(is_empty==true)is_gameover=1; 
    //若输入传送带上所有元素的filled都为0（没有数字），则游戏结束

    return ;
}

void outbox(void)
{
    if(current.filled==0)
    {
        cout<<"Error: You have no wood in your hand.\n"; 
        return ;                    //没有当前积木，报错
    }

    output.insert(output.begin(),{current.num,1});  
    current.filled=0;   
    //将current.num放在output.num上，删除current； (后端内容)

    //以下让机器人移到右边
    while (nowx<33)
	{
		movetoright();
		//其中包含Sleep(100)
	}

    //放下木块


	//以下更新并显示outwood内容
	COORD coord = { 0 };		//光标结构体定义
    int len_outwood=distance(output.begin(),output.end());  //这是outwood中有元素的木块的个数
	for (int i = len_outwood-1 ; i >= 0; i--)
	{
		coord.X = outwood.body[i].X + 2;
		coord.Y = outwood.body[i].Y + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
		//putchar(output[i]);
        printf("%d",output[i].num);
	}
	/*coord.X = outwood.body[0].X + 2;
	coord.Y = outwood.body[0].Y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	putchar(output[0]);*/   
    //这里一整节删掉，因为已经在output矢量最前面插入了一个元素，并在循环中遍历到了第0个元素

    PrintWood(nowx-6,nowy-3, 0 , 0);
    //把机器人手中的木块设为X

}

void add(int X)
{
    if(current.filled==0)
    {
        cout<<"Error: You have no wood in your hand.\n";
    } //没有当前积木，报错
    if(X>=space_max)
    {
        cout<<"Error: Space X does now exists.\n";
        return ;
    }                //X号空地不存在，报错
    if(space[X].filled==0)
    {
        cout<<"Error: Space X is empty.\n";
        return ;
    }               //X号空地没有积木，报错

    //更新并显示手中的积木
    current.num+=space[X].num;
    PrintWood(current_coord.X, current_coord.Y, current.filled, current.num);
}

void sub(int X)
{
    if(current.filled==0); //没有当前积木，报错
    if(X>=space_max)
    {
        cout<<"Error: Space X does now exists.\n";
        return ;
    }                //X号空地不存在，报错
    if(space[X].filled==0)
    {
        cout<<"Error: Space X is empty.\n";
        return ;
    }               //X号空地没有积木，报错

    //更新并显示手中的积木
    current.num-=space[X].num;
    PrintWood(current_coord.X, current_coord.Y, current.filled, current.num);
}

void copyto(int X)
{
    if(current.filled==0); //没有当前积木，报错
    if(X>=space_max)
    {
        cout<<"Error: Space X does now exists.\n";
        return ;
    }                //X号空地不存在，报错

    //以下复制当前积木到X号空地 ，并显示
    space[X].num=current.filled;
    space[X].filled=1;
    PrintWood(emptywood.body[X].X, emptywood.body[X].Y, 1, space[X].num);
}

void copyfrom(int X)
{
    if(X>=space_max)
    {
        cout<<"Error: Space X does now exists.\n";
        return ;
    }                //X号空地不存在，报错
    if(space[X].filled==0)
    {
        cout<<"Error: Space X is empty.\n";
        return ;
    }               //X号空地没有积木，报错

    //以下复制X号空地到当前积木，并显示；
    current.num=space[X].num;
    current.filled=1;
    PrintWood(current_coord.X, current_coord.Y, 1, current.num);
}

void jump(int X)
{

}