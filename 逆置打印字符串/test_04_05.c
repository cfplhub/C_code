#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void reverse(char* left, char* right)
{ 
	//���� ָ��Ϊ����������
	assert(left);
	assert(right);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	//����
	char arr[101] = { 0 };

	gets(arr);

	int len = strlen(arr);

	//����
	reverse(arr, arr + len - 1);
	
	char* start = arr;

	while (*start)
	{
	
		char* end = start;

		while (*end != ' ' && *end != '\0')
		{
			end++;
		}

		reverse(start, end - 1);

		if (*end != '\0')
			end++;

		start = end;
	}


	//���

	printf("%s\n\n", arr);

	return 0;
}