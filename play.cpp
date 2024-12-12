#include "base.h"
void Play1()
{
	/*	�������У�1, 2
		Ŀ��������У�1, 2
		���ÿյ�����0
		����ָ���inbox, outbox*/
	initUI1();
	printf("�������У�1, 2 \nĿ��������У�1, 2 \n���ÿյ�����0 \n ����ָ���inbox, outbox\n���������ָ������\n");
	inputnum = 2;
	outputnum = 0;
	strcpy(input[0],"1");
	strcpy(input[1],"2");
	cin >> n;
	printf("�밴���������ָ��:");
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
	//������һ����ִ������
	for (int i = 1; i <= n; i++)
	{
		setposition(58,2+i);
		putchar('>');//��>��ָ��������ִ�е�����
		if (strcmp(instruction[i].s, "inbox") == 0) inbox();
		else if (strcmp(instruction[i].s, "outbox") == 0) outbox();
		else
		{
			cout << "Error on instruction " << i ;
			return;
		}
		if(inboxnon) Judge1();
		//ÿ��ָ��ִ����󣬼�ͷ����
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
	/*	�������У�3,9,5,1,-2,-2,9,-9
		Ŀ��������У�-6,6,4,-4,0,0,18,-18
		���ÿյ�����3
		����ָ���inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI2();
	setposition(0,19);//���ù��λ��
	printf("�������У�3,9,5,1,-2,-2,9,-9 \nĿ��������У�-6,6,4,-4,0,0,18,-18 \n���ÿյ�����3 \n\
����ָ���inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n���������ָ������\n");
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
	printf("�밴���������ָ��:");
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
			setposition(59,2+i);	//���ù��λ��
		else if(i>20&&i<=40) setposition(79,2+i-20);
		else if(i>40&&i<=60) setposition(99,2+i-40);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//������һ����ִ������
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
			setposition(58,2+i);	//���ù��λ��
		else if(i>20&&i<=40) setposition(78,2+i-20);
		else if(i>40&&i<=60) setposition(98,2+i-40);
		putchar('>');//��>��ָ��������ִ�е�����
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
		//ÿ��ָ��ִ����󣬼�ͷ����
		if(nowi<=20)
			setposition(58,2+nowi);	//���ù��λ��
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
	/*	�������У�6,2,7,7,-9,3,-3,-3
		Ŀ��������У�7,-3
		���ÿյ�����3
		����ָ���inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero*/
	initUI3();
	setposition(0,19);//���ù��λ��
	printf("�������У�6,2,7,7,-9,3,-3,-3 \nĿ��������У�7,-3 \n���ÿյ�����3 \n\
����ָ���inbox,outbox,copyfrom,copyto,add,sub,jump,jumpifzero\n���������ָ������\n");
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
	printf("�밴���������ָ��:");
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
			setposition(59,2+i);	//���ù��λ��
		else if(i>25&&i<=50) setposition(79,2+i-25);
		else if(i>50&&i<=75) setposition(99,2+i-50);
		printf("%d %s ", i, instruction[i].s);
		if (strcmp(instruction[i].s, "inbox") != 0 && strcmp(instruction[i].s, "outbox") != 0)
			printf("%d", instruction[i].num);
	}
	//������һ����ִ������
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
			setposition(58,2+nowi);	//���ù��λ��
		else if(nowi>25&&nowi<=50) setposition(78,2+nowi-25);
		else if(nowi>50&&nowi<=75) setposition(98,2+nowi-50);
		putchar('>');//��>��ָ��������ִ�е�����
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
		//ÿ��ָ��ִ����󣬼�ͷ����
		if(nowi<=25)
			setposition(58,2+nowi);	//���ù��λ��
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
