#define _CRT_SERCURE_NO_WARININGS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include<assert.h>

//1.空指针
//2、空字符串
//3、空格
//4、+-
//5、越界
//6、非数字字符

enum Status
{
	VALID,
	INVALID
}sta = INVALID;//默认非法

int my_atoi(const char* str)
{
	int flag = 1;
	//断言，空指针即跳出
	assert(str);

	if (*str == '\0')
		return 0;//非法0

	//跳出空白字符
	while(isspace(*str))
	{
		str++;
	}

	//+-

	if (*str == '+')
	{
		flag = 1;
		str++;
	}

	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	long long ret = 0;

	while (*str)
	{
		//判断是不是数字
		if (isdigit(*str))
		{
			//越界
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return (int)ret;
		}
		str++;
	}

	if (*str == '\0')
	{
		sta = VALID;
	}
	return (int)ret; 
}


int main()
{

	char arr[200] = "111111111111111123456";

	int ret = my_atoi(arr);

	//printf("%d ", ret);

	if (sta == INVALID)
	{
		printf("非法返回：%d\n", ret);
	}

	else if (sta == VALID)
	{
		printf("合法返回：%d\n", ret); 
	}


	return 0;
}