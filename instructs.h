#pragma once

#include "initialization_v2.h"
#include<vector>
using namespace std;

void instruct(string, int);  //指令
void inbox(void);
void outbox(void);
void add(int X);
void copyto(int X);
void copyfrom(int X);
void jump(int X);


struct conveyer
{
    int num;         //用来记录数字
    bool filled;     //用来记录是否有数字，若有数字，则filled=1
};

conveyer current={0,0};     //当前积木

vector<conveyer> input;     //输入传送带
vector<conveyer> output;    //输出传送带
vector<conveyer> space;     //空地
vector<conveyer> :: iterator it_input=input.begin();
vector<conveyer> :: iterator it_output=output.begin();
vector<conveyer> :: iterator it_space=space.begin();     //三个矢量的迭代器，先定义，暂时不用

int space_max=5;    //暂且将空地最大数设为5，反正要根据选择的关卡进行修改，这里是随便设的

bool is_gameover=0;  //判断游戏是否结束