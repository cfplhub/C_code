#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a, b = 0;

	scanf("%d %d", &a, &b);

	//int m = a > b ? a : b;

	//while (1)
	//{
	//	if (m % a == 0 && m % b == 0)
	//	{
	//		break;
	//	}

	//	m++;
	//}

	//printf("%d\n", m);

	int i = 1;

	while (a * i % b)
	{
		i++;
	}

	printf("%d", a * i);

	return 0;
}