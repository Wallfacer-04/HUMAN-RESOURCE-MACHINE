#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

#define HEIGHT 50
#define WIDE 120
#define MAXN WIDE*HEIGHT//机器人最大占多少个位置
//机器人位置初始化
int n; 
bool inboxnon;
bool flag;//标记是否出错
int emptynum;//当前空地数
char s1[100];

int nowx=20, nowy=4;//全局变量记录当前机器人的左上角位置,初始值为20,4
int inputnum,outputnum,emptyputnum;

bool isnowwood;
char nowwood[5];

char input[100][50];//记录输入序列
char output[100][50];//记录当下输出传送带上的值
char emptyput[100][500];//记录空地上的值

bool mark[100];//标记instruction是否有问题 

struct Instruction 
{
	char s[100];
	int num;
}instruction[1002];

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
	int size;//指定货物的大小
}inwood,outwood,emptywood,awood;
//inwood输入传送带，outwood输出传送带，emptywood空地,awood当前搬运

int score = 0;//分数

//函数声明
void initrank();//选择关卡

void initUI1();
void initUI2();
void initUI3();

void Judge1();
void Judge2();
void Judge3();

int tonum(char []);
void tostring(char [],int);

void inbox();
void outbox();
void add(int);
void sub(int);
void copyto(int);
void copyfrom(int);
void jump(int,int*);
void jumpifzero(int,int*);
bool notinstruction(char []);
int tonumstruction(char []);

int main()
{
	for(int i=0;i<100;i++)
		input[i][0]='X';
	for(int i=0;i<100;i++)
		output[i][0]='X';

	initrank();//选择关卡界面，其中调用Play函数
	return 0;
}
void Play1()
{
	/*	输入序列：1, 2
		目标输出序列：1, 2
		可用空地数：0
		可用指令集：inbox, outbox*/
	inputnum = 2;
	outputnum = 0;
	strcpy(input[0],"1");
	strcpy(input[1],"2");
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char s[100];
		cin >> instruction[i].s;
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else if(notinstruction(instruction[i].s))
		{
			gets(s);
			mark[i]=1;
			continue;
		} 
		gets(s);
		if(strlen(s)!=1)
		{
			mark[i]=1;
		}
		else if(s[0]<'0'||s[0]>'9')
		{
			mark[i]=1;
		}
		else instruction[i].num=s[0];
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if(inboxnon) Judge1();
		//每条指令执行完后，箭头下移
		if (flag)
		{
			cout << "Error on instruction " << i ;
			return;
		}
	}
	Judge1();
}
void Play2()
{
	/*	输入序列：3,9,5,1,-2,-2,9,-9
		目标输出序列：-6,6,4,-4,0,0,18,-18
		可用空地数：3
		可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
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
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		if(mark[i]) 
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if(strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num,&i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num,&i);
		else
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if(inboxnon) Judge2();
		if (flag)
		{
			cout << "Error on instruction " << i ;
			return;
		}
	}
	Judge2();
}
void Play3()
{
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
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		if(mark[i]) 
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if(strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num,&i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num,&i);
		else
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if(inboxnon) Judge3();
		if (flag)
		{
			cout << "Error on instruction " << i ;
			return;
		}
	}
	Judge3();
}

void initrank()
{
	int m;
	cin >> m;

	if (m == 1) Play1();
	if (m == 2) Play2();
	if (m == 3) Play3();
	return;
}

//初始化界面控界,画出机器人，inwood，outwood，emptywood


void Judge1()//判断游戏第一关胜负
{ 
	if (outputnum == 2 && strcmp(output[0],"2")==0&& strcmp(output[1],"1")==0)
		cout << "Success";
	else cout << "Fail";
	exit(0);
}
void Judge2()//判断游戏第二关胜负
{
	if (outputnum == 8 && (strcmp(output[0],"-18")==0) && (strcmp(output[1],"18")==0)&&(strcmp(output[2],"0")==0)&&
	(strcmp(output[3],"0")==0)&&(strcmp(output[4],"-4")==0)&&(strcmp(output[5],"4")==0)
	&&(strcmp(output[6],"6")==0)&&(strcmp(output[7],"-6")==0))
		cout << "Success";
	else cout << "Fail";
	exit(0);
}
void Judge3()//判断游戏第三关胜负
{
	if (outputnum == 2 && (strcmp(output[0],"-3")==0) && (strcmp(output[1],"7")==0) )
		cout << "Success";
	else cout << "Fail";
	exit(0);
}

void inbox()
{
	if (inputnum == 0)//结束游戏
	{
		inboxnon=1;
		return;
	}
	//拿起木块
	isnowwood = true;
	strcpy(nowwood,input[0]);
	for (int i = 0; i < inputnum; i++)
	{
		strcpy(input[i], input[i + 1]);
	}
	inputnum--;
}

void outbox()
{
	
	if (isnowwood == false)//错误情况
	{
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
	}
	strcpy(output[0] , nowwood);
}
void add(int x)
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	tostring(nowwood,tonum(nowwood)+tonum(emptyput[x]));
}
void sub(int x)//与add相比只把+改成了- 
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	tostring(nowwood,tonum(nowwood)-tonum(emptyput[x]));
}
void copyto(int x)
{
	if ((isnowwood == false||x>=emptynum))//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	//放下物块 
	isnowwood=false;
	strcpy(emptyput[x] ,nowwood);
}

void copyfrom(int x)
{
	if (x>=emptynum||emptyput[x][0]=='X')//错误情况
	{
		flag = 1;//标志出错
		return;
	}
	//不管有没有，生成物块，isnowwood置为真 
	strcpy(nowwood,emptyput[x]);
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
bool notinstruction(char s[])
{
	if(strcmp(s,"inbox")!=0&&strcmp(s,"outbox")!=0&&strcmp(s,"add")!=0&&strcmp(s,"sub")!=0
	&&strcmp(s,"copyto")!=0&&strcmp(s,"copyfrom")!=0&&strcmp(s,"jump")!=0&&strcmp(s,"jumpifzero")!=0)
	{
		return 1;
	}
	else return 0;
}
int tonum(char s[])//字符串转化成整数 
{
	
	int len=strlen(s);
	int num=0;
	int flag=1;
	for(int i=0;i<len;i++){
		if(s[i]=='-')
		{
			flag=-1;
			continue;
		}
		else
		{
			num=num*10+s[i]-'0';
		}
	}
	return flag*num;
}
void tostring(char s[],int num)//传址调用 
{
	if(num==0) 
	{
		strcpy(s,"0\0\0");
		return;
	}
	int cnt=0;
	int num1=num;
	while(num1!=0)//统计位数 
	{
		num1/=10;
		cnt++;
	}
	if(num<0)
		{
			num=-num;
			s[0]='-';
			cnt++;
			for(int i=cnt-1;i>=1;i--)
			{
				s[i]=num%10+'0';
				num/=10;
			}
		}
	else
	{
		for(int i=cnt-1;i>=0;i--)
		{
			s[i]=num%10+'0';
			num/=10;
		}
	}
	return;
}
int tonumstruction(char s2[])
{
	int len=strlen(s2);
	int p1=0,p2=len-1;
	bool flag1=0,flag2=0; 
	while(s2[p1]==' ')
	{
		p1++;
	}
	while(s2[p2]==' ')
	{
		p2--;
	}
	for(int i=p1;i<=p2;i++)
	{
		if(s2[i]>'9'||s2[i]<'0')
			return -1;
	}
	s2[p2+1]='\0';
	int numb=tonum(s2+p1);
	if(numb>n||numb<0) return -1;
	return numb;
}
