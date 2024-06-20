#define _CRT_SERCURE_NO_WARININGS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include<assert.h>

//1.��ָ��
//2�����ַ���
//3���ո�
//4��+-
//5��Խ��
//6���������ַ�

enum Status
{
	VALID,
	INVALID
}sta = INVALID;//Ĭ�ϷǷ�

int my_atoi(const char* str)
{
	int flag = 1;
	//���ԣ���ָ�뼴����
	assert(str);

	if (*str == '\0')
		return 0;//�Ƿ�0

	//�����հ��ַ�
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
		//�ж��ǲ�������
		if (isdigit(*str))
		{
			//Խ��
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
		printf("�Ƿ����أ�%d\n", ret);
	}

	else if (sta == VALID)
	{
		printf("�Ϸ����أ�%d\n", ret); 
	}


	return 0;
}