#include "base.h"
void Play1()
{
	/*	输入序列：1, 2
		目标输出序列：1, 2
		可用空地数：0
		可用指令集：inbox, outbox*/
	initUI1();
	printf("输入序列：1, 2 \n目标输出序列：1, 2 \n可用空地数：0 \n 可用指令集：inbox, outbox\n请输入你的指令数：\n");
	inputnum = 2;
	outputnum = 0;
	strcpy(input[0], "1");
	strcpy(input[1], "2");
	
	char tmp = cin.get();
	char nnn[10000];
	if(tmp=='\n')cin.getline(nnn, 10000);
	else
	{
		nnn[0] = tmp;
		cin.getline(nnn + 1, 10000 - 1);
	}
	int n = tonumstruction(nnn);
	if (n == -1)
	{
		cout << "格式错误，请重新输入\n\n";
		system("pause");
		system("cls");
		Play1();
	}

	printf("请按行输入你的指令:\n");
	for (int i = 1; i <= n; i++)
	{
		cin >> instruction[i].s;
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)
		{
			if (cin.get() == ' ')
			{
				mark[i] = 1;
				cin.getline(instruction[i].appendix, 10000);
			}
			continue;
		}
		else cin.getline(instruction[i].appendix, 10000);
	}
	system("cls");
	initUI1();

	for (int i = 1; i <= n; i++)
	{
		if (i <= 25)
			setposition(59, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(79, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(99, 2 + i - 50);
		printf("%d %s ", i, instruction[i].s);
		printf(" %s", instruction[i].appendix);
	}

	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi = i; 

		if (i <= 25)
			setposition(58, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(78, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(98, 2 + i - 50);
		putchar('>');//将>号指向当下正在执行的命令

		if (mark[i] == 1)
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}

		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i<<endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
		if (inboxnon) Judge1();
		//每条指令执行完后，箭头下移
		if (nowi <= 25)
			setposition(58, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98, 2 + nowi - 50);
		putchar(' ');
		if (flag)
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i<<endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
	}
	deletenowwood();
	Judge1();
}
void Play2()
{
	/*	输入序列：3,9,5,1,-2,-2,9,-9
		目标输出序列：-6,6,4,-4,0,0,18,-18
		可用空地数：3
		可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI2();
	setposition(0, 19);//设置光标位置
	printf("输入序列：3,9,5,1,-2,-2,9,-9 \n目标输出序列：-6,6,4,-4,0,0,18,-18 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
	inputnum = 8;
	outputnum = 0;
	emptynum = 3;
	strcpy(input[0], "3");
	strcpy(input[1], "9");
	strcpy(input[2], "5");
	strcpy(input[3], "1");
	strcpy(input[4], "-2");
	strcpy(input[5], "-2");
	strcpy(input[6], "9");
	strcpy(input[7], "-9");
	//n记录指令数； 
	char tmp = cin.get();
	char nnn[10000];
	if (tmp == '\n')cin.getline(nnn, 10000);
	else
	{
		nnn[0] = tmp;
		cin.getline(nnn + 1, 10000 - 1);
	}
	int n = tonumstruction(nnn);
	if (n == -1)
	{
		cout << "格式错误，请重新输入\n\n";
		system("pause");
		system("cls");
		Play2();
	}

	printf("请按行输入你的指令:\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)
		{
			if (cin.get() == ' ')
			{
				mark[i] = 1;
				cin.getline(instruction[i].appendix, 10000);
			}
			continue;
		}
		else if (notinstruction(instruction[i].s))
		{
			gets_s(instruction[i].appendix);
			mark[i] = 1;
			continue;
		}
		gets_s(instruction[i].appendix);
		instruction[i].num = tonumstruction(instruction[i].appendix);
		if (instruction[i].num == -1 )
		{
			mark[i] = 1;
		}
		if (strcmp(instruction[i].s, "jump") == 0 || strcmp(instruction[i].s, "jumpifzero") == 0)
		{
			if (instruction[i].num >= n)mark[i] = 1;
		}
		else
		{
			if (instruction[i].num > 2) mark[i] = 1;
		}
	}
	system("cls");
	initUI2();
	for (int i = 1; i <= n; i++)
	{
		if (i <= 25)
			setposition(59, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(79, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(99, 2 + i - 50);
		printf("%d %s ", i, instruction[i].s);
		printf(" %s", instruction[i].appendix);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi = i;
		
		if (i <= 25)
			setposition(58, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(78, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(98, 2 + i - 50);
		putchar('>');//将>号指向当下正在执行的命令

		if (mark[i])
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}

		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if (strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num, &i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num, &i);
		else
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
		if (inboxnon) Judge2();
		//每条指令执行完后，箭头下移
		if (nowi <= 25)
			setposition(58, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98, 2 + nowi - 50);
		putchar(' ');
		if (flag)
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
	}
	deletenowwood();
	Judge2();
}
void Play3()
{
	/*	输入序列：6,2,7,7,-9,3,-3,-3
		目标输出序列：7,-3
		可用空地数：3
		可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI3();
	setposition(0, 19);//设置光标位置
	printf("输入序列：6,2,7,7,-9,3,-3,-3 \n目标输出序列：7,-3 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
	inputnum = 8;
	outputnum = 0;
	emptynum = 3;
	strcpy(input[0], "6");
	strcpy(input[1], "2");
	strcpy(input[2], "7");
	strcpy(input[3], "7");
	strcpy(input[4], "-9");
	strcpy(input[5], "3");
	strcpy(input[6], "-3");
	strcpy(input[7], "-3");
	//n记录指令数； 
	char tmp = cin.get();
	char nnn[10000];
	if (tmp == '\n')cin.getline(nnn, 10000);
	else
	{
		nnn[0] = tmp;
		cin.getline(nnn + 1, 10000 - 1);
	}
	int n = tonumstruction(nnn);
	if (n == -1)
	{
		cout << "格式错误，请重新输入\n\n";
		system("pause");
		system("cls");
		Play3();
	}

	printf("请按行输入你的指令:\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)
		{
			if (cin.get() == ' ')
			{
				mark[i] = 1;
				cin.getline(instruction[i].appendix, 10000);
			}
			continue;
		}
		else if (notinstruction(instruction[i].s))
		{
			gets_s(instruction[i].appendix);
			mark[i] = 1;
			continue;
		}
		gets_s(instruction[i].appendix);
		instruction[i].num = tonumstruction(instruction[i].appendix);
		if (instruction[i].num == -1)
		{
			mark[i] = 1;
		}

		if (strcmp(instruction[i].s, "jump") == 0 || strcmp(instruction[i].s, "jumpifzero") == 0)
		{
			if (instruction[i].num >= n)mark[i] = 1;
		}
		else
		{
			if (instruction[i].num > 2) mark[i] = 1;
		}

	}
	system("cls");
	initUI3();
	for (int i = 1; i <= n; i++)
	{
		if (i <= 25)
			setposition(59, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(79, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(99, 2 + i - 50);
		printf("%d %s ", i, instruction[i].s);
		printf(" %s", instruction[i].appendix);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi = i;
		
		if (nowi <= 25)
			setposition(58, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98, 2 + nowi - 50);
		putchar('>');//将>号指向当下正在执行的命令

		if (mark[i])
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}

		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else if (strcmp(instruction[i].s, "add") == 0) add(instruction[i].num);
		else if (strcmp(instruction[i].s, "sub") == 0) sub(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else if (strcmp(instruction[i].s, "jump") == 0) jump(instruction[i].num, &i);
		else if (strcmp(instruction[i].s, "jumpifzero") == 0) jumpifzero(instruction[i].num, &i);
		else
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
		if (inboxnon) Judge3();
		//每条指令执行完后，箭头下移
		if (nowi <= 25)
			setposition(58, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98, 2 + nowi - 50);
		putchar(' ');
		if (flag)
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
	}
	deletenowwood();
	Judge3();
}

//可用指令集：inbox,outbox,copyto,copyfrom
//输入序列：r,w,d,l,o,h,e
//目标输出序列： dlrowolleh ("helloworld"倒着写")
void Play4()
{
	initUI4();

	setposition(0, 19);//设置光标位置
	printf("输入序列：r,w,d,l,o,h,e \n目标输出序列：d,l,r,o,w,o,l,l,e,h \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto\n请输入你的指令数：\n");
	inputnum = 7;
	outputnum = 0;
	emptynum = 3;
	strcpy(input[0], "r");
	strcpy(input[1], "w");
	strcpy(input[2], "d");
	strcpy(input[3], "l");
	strcpy(input[4], "o");
	strcpy(input[5], "h");
	strcpy(input[6], "e");
	//n记录指令数； 
	char tmp = cin.get();
	char nnn[10000];
	if (tmp == '\n')cin.getline(nnn, 10000);
	else
	{
		nnn[0] = tmp;
		cin.getline(nnn + 1, 10000 - 1);
	}
	int n = tonumstruction(nnn);
	if (n == -1)
	{
		cout << "格式错误，请重新输入\n\n";
		system("pause");
		system("cls");
		Play4();
	}

	printf("请按行输入你的指令:\n");

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)
		{
			if (cin.get() == ' ')
			{
				mark[i] = 1;
				cin.getline(instruction[i].appendix, 10000);
			}
			continue;
		}
		else if (notinstruction(instruction[i].s))
		{
			gets_s(instruction[i].appendix);
			mark[i] = 1;
			continue;
		}
		gets_s(instruction[i].appendix);
		instruction[i].num = tonumstruction(instruction[i].appendix);
		if (instruction[i].num == -1)
		{
			mark[i] = 1;
		}
		if (strcmp(instruction[i].s, "copyto") == 0 || strcmp(instruction[i].s, "copyfrom") == 0)
		{
			if (instruction[i].num > 2)mark[i] = 1;
		}
	}

	system("cls");
	initUI4();
	for (int i = 1; i <= n; i++)
	{
		if (i <= 25)
			setposition(59+6, 2 + i);	//设置光标位置
		else if (i > 25 && i <= 50) setposition(79+6, 2 + i - 25);
		else if (i > 50 && i <= 75) setposition(99+6, 2 + i - 50);
		printf("%d %s ", i, instruction[i].s);
		printf(" %s", instruction[i].appendix);
	}

	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi = i;

		if (nowi <= 25)
			setposition(58+6, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78+6, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98+6, 2 + nowi - 50);
		putchar('>');//将>号指向当下正在执行的命令

		if (mark[i])
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n";
			system("pause");
			system("cls");
			selectlevel();
		}

		if (strcmp(instruction[i].s, "inbox") == 0) inbox_4();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox_4();
		else if (strcmp(instruction[i].s, "copyto") == 0) copyto(instruction[i].num);
		else if (strcmp(instruction[i].s, "copyfrom") == 0) copyfrom(instruction[i].num);
		else
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
		if (inboxnon) Judge4();
		//每条指令执行完后，箭头下移
		if (nowi <= 25)
			setposition(58+6, 2 + nowi);	//设置光标位置
		else if (nowi > 25 && nowi <= 50) setposition(78+6, 2 + nowi - 25);
		else if (nowi > 50 && nowi <= 75) setposition(98+6, 2 + nowi - 50);
		putchar(' ');
		if (flag)
		{
			Sleep(1250);
			system("cls");
			cout << "Error on instruction " << i << endl;
			Sleep(1000);
			cout << "Fail\n\n";
			system("pause");
			system("cls");
			selectlevel();
		}
	}
	deletenowwood();
	Judge4();
}
