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
#define MAXN WIDE*HEIGHT//���������ռ���ٸ�λ��
//������λ�ó�ʼ��
int n; 
bool inboxnon;
bool flag;//����Ƿ����
int emptynum;//��ǰ�յ���
char s1[100];

int nowx=20, nowy=4;//ȫ�ֱ�����¼��ǰ�����˵����Ͻ�λ��,��ʼֵΪ20,4
int inputnum,outputnum,emptyputnum;

bool isnowwood;
char nowwood[5];

char input[100][50];//��¼��������
char output[100][50];//��¼����������ʹ��ϵ�ֵ
char emptyput[100][500];//��¼�յ��ϵ�ֵ

bool mark[100];//���instruction�Ƿ������� 

struct Instruction 
{
	char s[100];
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
void initrank();//ѡ��ؿ�

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

	initrank();//ѡ��ؿ����棬���е���Play����
	return 0;
}
void Play1()
{
	/*	�������У�1, 2
		Ŀ��������У�1, 2
		���ÿյ�����0
		����ָ���inbox, outbox*/
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
	//������һ����ִ������
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
		//ÿ��ָ��ִ����󣬼�ͷ����
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
	/*	�������У�3,9,5,1,-2,-2,9,-9
		Ŀ��������У�-6,6,4,-4,0,0,18,-18
		���ÿյ�����3
		����ָ���inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
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
	//n��¼ָ������ 
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
	//������һ����ִ������
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
	//n��¼ָ������ 
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
	//������һ����ִ������
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

//��ʼ������ؽ�,���������ˣ�inwood��outwood��emptywood


void Judge1()//�ж���Ϸ��һ��ʤ��
{ 
	if (outputnum == 2 && strcmp(output[0],"2")==0&& strcmp(output[1],"1")==0)
		cout << "Success";
	else cout << "Fail";
	exit(0);
}
void Judge2()//�ж���Ϸ�ڶ���ʤ��
{
	if (outputnum == 8 && (strcmp(output[0],"-18")==0) && (strcmp(output[1],"18")==0)&&(strcmp(output[2],"0")==0)&&
	(strcmp(output[3],"0")==0)&&(strcmp(output[4],"-4")==0)&&(strcmp(output[5],"4")==0)
	&&(strcmp(output[6],"6")==0)&&(strcmp(output[7],"-6")==0))
		cout << "Success";
	else cout << "Fail";
	exit(0);
}
void Judge3()//�ж���Ϸ������ʤ��
{
	if (outputnum == 2 && (strcmp(output[0],"-3")==0) && (strcmp(output[1],"7")==0) )
		cout << "Success";
	else cout << "Fail";
	exit(0);
}

void inbox()
{
	if (inputnum == 0)//������Ϸ
	{
		inboxnon=1;
		return;
	}
	//����ľ��
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
	
	if (isnowwood == false)//�������
	{
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
	}
	strcpy(output[0] , nowwood);
}
void add(int x)
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	tostring(nowwood,tonum(nowwood)+tonum(emptyput[x]));
}
void sub(int x)//��add���ֻ��+�ĳ���- 
{
	if ((isnowwood == false||x>=emptynum)||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	tostring(nowwood,tonum(nowwood)-tonum(emptyput[x]));
}
void copyto(int x)
{
	if ((isnowwood == false||x>=emptynum))//�������
	{
		flag = 1;//��־����
		return;
	}
	//������� 
	isnowwood=false;
	strcpy(emptyput[x] ,nowwood);
}

void copyfrom(int x)
{
	if (x>=emptynum||emptyput[x][0]=='X')//�������
	{
		flag = 1;//��־����
		return;
	}
	//������û�У�������飬isnowwood��Ϊ�� 
	strcpy(nowwood,emptyput[x]);
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
bool notinstruction(char s[])
{
	if(strcmp(s,"inbox")!=0&&strcmp(s,"outbox")!=0&&strcmp(s,"add")!=0&&strcmp(s,"sub")!=0
	&&strcmp(s,"copyto")!=0&&strcmp(s,"copyfrom")!=0&&strcmp(s,"jump")!=0&&strcmp(s,"jumpifzero")!=0)
	{
		return 1;
	}
	else return 0;
}
int tonum(char s[])//�ַ���ת�������� 
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
void tostring(char s[],int num)//��ַ���� 
{
	if(num==0) 
	{
		strcpy(s,"0\0\0");
		return;
	}
	int cnt=0;
	int num1=num;
	while(num1!=0)//ͳ��λ�� 
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
