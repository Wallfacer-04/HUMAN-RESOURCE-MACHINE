#include "base.h"
void Judge1()//判断游戏第一关胜负
{
	COORD coord;
	coord.X = 0;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 2 && output[0][0] == '2' && output[1][0] == '1')
	{
		cout << "Success\n";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin >> nn;
		fin.close();
		if (nn < 2)
		{
			ofstream fout;
			fout.open("in.txt");
			fout << 2;
			fout.close();
		}

	}
	else cout << "Fail\n";
	system("pause");
	system("cls");
	selectlevel();
}
void Judge2()//判断游戏第二关胜负
{
	setposition(0, 29);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 8 && (strcmp(output[0], "-18") == 0) && (strcmp(output[1], "18") == 0) && (strcmp(output[2], "0") == 0) &&
		(strcmp(output[3], "0") == 0) && (strcmp(output[4], "-4") == 0) && (strcmp(output[5], "4") == 0)
		&& (strcmp(output[6], "6") == 0) && (strcmp(output[7], "-6") == 0))
	{
		cout << "Success\n";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin >> nn;
		fin.close();
		if (nn < 3)
		{
			ofstream fout;
			fout.open("in.txt");
			fout << 3;
			fout.close();
		}

		system("pause");
		system("cls");
		selectlevel();
	}
	else cout << "Fail\n";
	
	system("pause");
	system("cls");
	selectlevel();
}
void Judge3()//判断游戏第三关胜负
{
	setposition(0, 29);//设置光标位置
	system("pause");
	system("cls");
	if (outputnum == 2 && (strcmp(output[0], "-3") == 0) && (strcmp(output[1], "7") == 0))
	{
		cout << "Success\n";
		ifstream fin;
		fin.open("in.txt");
		int nn;//记录第几关 
		fin >> nn;
		fin.close();
		if (nn < 4)
		{
			ofstream fout;
			fout.open("in.txt");
			fout << 4;
			fout.close();
		}

		system("pause");
		system("cls");
		selectlevel();
	}
	else cout << "Fail\n";
	
	system("pause");
	system("cls");
	selectlevel();
}
