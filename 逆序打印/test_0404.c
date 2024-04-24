#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char arr[1000] = { 0 };

	gets(arr);

	int left = 0;

	int right = strlen(arr) - 1;


	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;

		left++;
		right--;
	}

	printf("%s \n", arr);

	return 0;
}