#include "base.h"
void Judge1()//�ж���Ϸ��һ��ʤ��
{ 
	COORD coord;
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
	system("pause");
	system("cls");
	if (outputnum == 2 && output[0][0] == '2' && output[1][0] == '1')
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//��¼�ڼ��� 
		fin>>nn;
		fin.close();
		if(nn<2)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 2;
		}
	}
	else cout << "Fail";
	exit(0);
}
void Judge2()//�ж���Ϸ�ڶ���ʤ��
{
	setposition(0,29);//���ù��λ��
	system("pause");
	system("cls");
	if (outputnum == 8 && (strcmp(output[0],"-18")==0) && (strcmp(output[1],"18")==0)&&(strcmp(output[2],"0")==0)&&
	(strcmp(output[3],"0")==0)&&(strcmp(output[4],"-4")==0)&&(strcmp(output[5],"4")==0)
	&&(strcmp(output[6],"6")==0)&&(strcmp(output[7],"-6")==0))
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//��¼�ڼ��� 
		fin>>nn;
		fin.close();
		if(nn<3)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 3;
		}
	}
	else cout << "Fail";
	exit(0);
}
void Judge3()//�ж���Ϸ������ʤ��
{
	setposition(0,29);//���ù��λ��
	system("pause");
	system("cls");
	if (outputnum == 2 && (strcmp(output[0],"-3")==0) && (strcmp(output[1],"7")==0))
	{
		cout << "Success";
		ifstream fin;
		fin.open("in.txt");
		int nn;//��¼�ڼ��� 
		fin>>nn;
		fin.close();
		if(nn<4)
		{
			ofstream fout;
			fout.open("in.txt");
			fout<< 4;
		}
	}
	else cout << "Fail";
	exit(0);
}
