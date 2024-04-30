#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a1[] = "I Love Li JiaHao !";
	char a2[] = "##################";

	int left = 0;
	int right = strlen(a2) - 1;


	while (left<=right)
	{
		a2[left] = a1[left];
		a2[right] = a1[right];
		printf("%s\n", a2);
		Sleep(1000);
		system("cls");
		left++;
		right--;

	}

	printf("%s\n", a2);

	return 0;

}