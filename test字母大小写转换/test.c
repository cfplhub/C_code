#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<ctype.h>

int main()
{
	char c = 0;

	//while (scanf("%c", &c) == 1)
	//{
	//	if (c >= 'a' && c <= 'z')
	//	{
	//		printf("%c\n", c-32);
	//	}

	//	else if (c >= 'A' && c <= 'Z')
	//	{
	//		printf("%c\n", c + 32);
	//	}
	//}
	//包含ctype头文件直接转换大小写字母
	//while (scanf("%c", &c) != EOF)
	//{
	//	if (islower(c))
	//    {
	//		printf("%c\n", toupper(c));
	//	}

	//	else if (isupper(c))
	//	{
	//		printf("%c\n", tolower(c));

	//		getchar();
	//	}

	//	
	//}

	//判断是否为字母，同样使用ctype头文件isalphabet

	while (scanf("%c", &c) != EOF)
	{
		if (isalpha(c))
		{    
			printf("%c is an alphabet\n", c);
			break;
		}

		else
		{
			printf("%c is not an alphabet\n", c);
			break;
		}


	}


	return 0;
}