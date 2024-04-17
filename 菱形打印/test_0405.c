#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int i, j = 0;

	int line;

	scanf("%d", &line);

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < line-i-1; j++)
		{
			printf(" ");
		}

		for (j = 0; j < (2*i)+1; j++)
		{
			printf("*");
		}

		printf("\n");

	}

	for (i = 0; i < line - 1; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}

		for (j = 0; j < 2*(line-i-1)-1; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}