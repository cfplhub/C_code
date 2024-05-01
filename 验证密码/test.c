#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char password[20] = { 0 };
	int i = 0;

	for(i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);

		if (strcmp(password, "abcdef") == 0)
		{
			printf("密码输入正确，登陆成功！\n");
			break;
		}

		else
		{
			printf("密码输入错误！您还有%d次机会输入密码！\n", 2 - i);
		}
	}

	if (i == 3)
	{
		printf("登陆失败！\n请重启系统输入密码！\n");
	}

	return 0;

}