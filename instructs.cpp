#include<iostream>
#include<vector>
using namespace std;

void instruct(string, int);  //指令
void inbox(void);
void outbox(void);
void add(int X);


struct conveyer
{
    int num;
    bool filled;
};

conveyer current={0,0};     //当前积木

vector<conveyer> input;     //输入传送带
vector<conveyer> output;    //输出传送带
vector<conveyer> space;     //空地
vector<conveyer> :: iterator it_input=input.begin();
vector<conveyer> :: iterator it_output=output.begin();
vector<conveyer> :: iterator it_space=space.begin();

int main()
{

    return 0;
}


void inbox(void)
{
    current.num=input[0].num;   //拿起input.num.num上第一个元素
    it_input=input.begin();
    input.erase(it_input);   //删除input.num的第一个元素

    //move_instruct(输入传送带的参数)    
    //以上让机器人移动到输入传送带旁

    bool is_empty=1;
    for(int i=0;i<10;i++)
    {
        if(input[i].filled==1)
        {
            is_empty=0;
            break;
        }
    }
    if(is_empty==true);  //gameover
    //此处添加判断输入传送带上元素是否全为-1
    //若全为-1，表示游戏结束

    return ;
}

void outbox(void)
{
    if(current.num==-1); //没有当前积木，报错

    int index=distance(output.begin(),it_output);
    output[index].num=current.num;   
    current.filled=0;   
    it_output++;
    //将current放在output.num上，删除current；
}

void add(int X)
{
    int index=distance(space.begin(),it_space);
    if(current.filled==0); //没有当前积木，报错
    //if(X>=space_max) X号空地不存在，报错
    if(space[index].filled==0); //X号空地没有积木，报错

    current.num+=space[index].num;
}
