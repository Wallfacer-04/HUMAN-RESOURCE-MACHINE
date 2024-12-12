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
	strcpy(input[0],"1");
	strcpy(input[1],"2");
	cin >> n;
	printf("请按行输入你的指令:");
	for (int i = 1; i <= n; i++)
	{
		cin >> instruction[i].s;
		if (strcmp(instruction[i].s, "inbox") == 0 || strcmp(instruction[i].s, "outbox") == 0)	continue;
		else cin >> instruction[i].num;
	}
	system("cls");
	initUI1();
	for (int i = 1; i <= n; i++)
	{
		setposition(59,2+i);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		setposition(58,2+i);
		putchar('>');//将>号指向当下正在执行的命令
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if(inboxnon) Judge1();
		//每条指令执行完后，箭头下移
		setposition(58,2+i);
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
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
	setposition(0,19);//设置光标位置
	printf("输入序列：3,9,5,1,-2,-2,9,-9 \n目标输出序列：-6,6,4,-4,0,0,18,-18 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
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
	printf("请按行输入你的指令:");
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
	system("cls");
	initUI2();
	for (int i = 1; i <= n; i++)
	{
		if(i<=20)
			setposition(59,2+i);	//设置光标位置
		else if(i>20&&i<=40) setposition(79,2+i-20);
		else if(i>40&&i<=60) setposition(99,2+i-40);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi=i;
		if(mark[i]) 
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}	
		if(i<=20)
			setposition(58,2+i);	//设置光标位置
		else if(i>20&&i<=40) setposition(78,2+i-20);
		else if(i>40&&i<=60) setposition(98,2+i-40);
		putchar('>');//将>号指向当下正在执行的命令
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
		//每条指令执行完后，箭头下移
		if(nowi<=20)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>20&&nowi<=40) setposition(78,2+nowi-20);
		else if(nowi>40&&nowi<=60) setposition(98,2+nowi-40);
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
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
	setposition(0,19);//设置光标位置
	printf("输入序列：6,2,7,7,-9,3,-3,-3 \n目标输出序列：7,-3 \n可用空地数：3 \n\
可用指令集：inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n请输入你的指令数：\n");
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
	printf("请按行输入你的指令:");
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
	system("cls");
	initUI3();
	for (int i = 1; i <= n; i++)
	{
		if(i<=25)
			setposition(59,2+i);	//设置光标位置
		else if(i>25&&i<=50) setposition(79,2+i-25);
		else if(i>50&&i<=75) setposition(99,2+i-50);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//接下来一条条执行命令
	for (int i = 1; i <= n; i++)
	{
		int nowi=i;
		if(mark[i])
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}	
		if(nowi<=25)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>25&&nowi<=50) setposition(78,2+nowi-25);
		else if(nowi>50&&nowi<=75) setposition(98,2+nowi-50);
		putchar('>');//将>号指向当下正在执行的命令
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
		//每条指令执行完后，箭头下移
		if(nowi<=25)
			setposition(58,2+nowi);	//设置光标位置
		else if(nowi>25&&nowi<=50) setposition(78,2+nowi-25);
		else if(nowi>50&&nowi<=75) setposition(98,2+nowi-50);
		putchar(' ');
		if (flag)
		{
			system("cls");
			cout << "Error on instruction " << i ;
			return;
		}
	}
	deletenowwood();
	Judge3();
}
void Play4()
{
		
}
