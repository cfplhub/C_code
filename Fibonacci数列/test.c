#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
//
//
//int main()
//{
//	int n = 0;
//	int a = 0;
//	int b = 1;
//	int c = 0;
//
//	scanf("%d", &n);
//
//	while (1)
//	{
//		if (n == 1)
//		{
//			printf("0\n");
//			break;
//		}
//
//		else if (n < b)
//		{
//			if (abs(n - a) > abs(n - b))
//			{
//				printf("%d\n", abs(n - b));
//			}
//			else
//				printf("%d\n", abs(n - a));
//			break;
//		}
//
//		c = a + b;
//		a = b;
//		b = c;
//	}
//
//
//
//	return 0;
//}

int main()
{
    int n = 0;
    int a = 1; // 斐波那契数列的第1项
    int b = 1; // 斐波那契数列的第2项
    int c = 0;

    scanf("%d", &n);

    if (n == 1 || n == 2) // 直接处理n为1或2的特殊情况
    {
        printf("%d\n", a);
    }
    else
    {
        while (b < n) // 当b小于n时继续循环
        {
            c = a + b; // 计算新的斐波那契数
            a = b;     // 更新a为b的值
            b = c;     // 更新b为新的斐波那契数
        }
        printf("%d\n", b); // 输出斐波那契数列的第n项
    }

    return 0;
}