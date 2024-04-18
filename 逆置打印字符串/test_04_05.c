#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

void reverse(char* left, char* right)
{ 
	//断言 指针为空立即跳出
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
	//输入
	char arr[101] = { 0 };

	gets(arr);

	int len = strlen(arr);

	//逆置
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


	//输出

	printf("%s\n\n", arr);

	return 0;
}