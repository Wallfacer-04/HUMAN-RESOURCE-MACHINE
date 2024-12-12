#include "base.h"
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
		strcpy(s,"0\0\0");//���� 
		return ;
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
bool notinstruction(char s[])
{
	if(strcmp(s,"inbox")!=0&&strcmp(s,"outbox")!=0&&strcmp(s,"add")!=0&&strcmp(s,"sub")!=0
	&&strcmp(s,"copyto")!=0&&strcmp(s,"copyfrom")!=0&&strcmp(s,"jump")!=0&&strcmp(s,"jumpifzero")!=0)
	{
		return 1;
	}
	else return 0;
}
