#include "initialization.cpp"
#include "print.cpp"
#include "function.cpp"
#include "operatestring.cpp"
#include "judge.cpp"
#include "play.cpp"
#include "base.h"
#define _CRT_SECUER_NO_WARNINGS
//������λ�ó�ʼ��

int main()
{
	/*for (int i = 1; i <= Height; i++)//����wide�����
	{
		for (int j = 1; j <= Wide; j++)
			cout << "#";
		cout << endl;
	}*/
	for(int i=0;i<20;i++)
		input[i][0]='X';
	for(int i=0;i<20;i++)
		output[i][0]='X';

	selectlevel();//ѡ��ؿ����棬���е���Play����
	COORD coord = { 0 };
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ�ø�ԭ
	system("pause");
	return 0;
}
void selectlevel()
{
	COORD coord = { 0 };		//���ṹ�嶨��
	
	ifstream fin;
	fin.open("in.txt");
	int n;
	fin >> n;
	fin.close();
	int m=10005;
	while (m > n)
	{
		coord.X = 30;
		coord.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
		printf("����ǰ��ͨ��������%d��", n);
		coord.X = 30;
		coord.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
		printf("�����ڿ���ѡ��Ĺؿ��У���");
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", i);
		}
		printf("��");
		coord.X = 30;
		coord.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
		printf("��Ӽ�������������Ĺؿ�");
		cin >> m;
		if (m > n)
		{
			coord.X = 30;
			coord.Y = 8;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
			cout << "��Ǹ������������,������ѡ��ؿ�";
		}
		coord.X = 30;
		coord.Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//���ù��λ��
		system("pause");
		system("cls");
	}

	if (m == 1) Play1();
	if (m == 2) Play2();
	if (m == 3) Play3();
	//if (m == 4) Play4();
	return;
}

