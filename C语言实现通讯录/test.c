#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#include<stdio.h>
#include<time.h>



void Menu()
{
	printf("***********************************\n");
	printf("*****1. add       2. del    *******\n");
	printf("*****3. find      4. modify *******\n");
	printf("*****5. show      6. sort   *******\n");
	printf("*****7. exit                *******\n");
	printf("***********************************\n");

}

int main()
{
	int input = 0;
	Contact con[MAX] ;
	InitContact(&con);//��ʼ��ͨѶ¼

	do
	{
		Menu();

		printf("����������ѡ��->:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DeleContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 7:
			printf("�˳�ͨѶ¼\n");
			return ;

		default:
			printf("�������\n");
			system("pasue");
			//sleep("100");
			system("cls");
			return -1;
			
			
		}

	} while (input);





	return 0;
}