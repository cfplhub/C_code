#define _CRT_SECURE_NO_WARNINGS

//���ú���ָ��ص�����
#include<stdio.h>
#include<Windows.h>

#define L_Blue system("color 01")


void Menu()
{
	L_Blue;
	printf("************** ��ӭʹ�üӼ��˳�������************\n");
	printf("*************     1.add     2.sub     ***********\n");
	printf("*************     3.mul     4.div     ***********\n");
	printf("*************     0.exit              ***********\n");
	printf("*************************************************\n");

}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void Calc(int(*pf)(int, int))
{
	printf("����������������\n");

	int x, y = 0;

	int ret = 0;

	scanf("%d %d", &x, &y);

	ret = pf(x, y);

	printf("����Ϊ���%d\n", ret);

	system("pause");
	system("cls");
}

int main()
{


	int input = 0;

	do
	{
		Menu();

		printf("��ѡ��:>");

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;

		case 2:
			Calc(Sub);
			break;

		case 3:
			Calc(Mul);
			break;

		case 4:
			Calc(Div);
			break;

		case 0:
			printf("���������^_^");
			break;

		default:
			printf("�����������������룡\n");
			system("pause");
			system("cls");
	

		}

	} while (input);

	return 0;
}