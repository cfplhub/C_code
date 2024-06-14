#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stddef.h>
//
//struct S
//{
//	char c1;
//	int c2;
//	char c3;
//};
//
//#define OFFSETOF(type, name) (size_t)&(((type*)0)->name)
//
//int main()
//{
//	struct S s = { 0 };
//
//	//offsetof 计算偏移量
//	//printf("%d\n", offsetof(struct S, c1));//0
//	//printf("%d\n", offsetof(struct S, c2));//4
//	//printf("%d\n", offsetof(struct S, c3));//8
//
//	printf("%d\n", OFFSETOF(struct S, c1));//0
//	printf("%d\n", OFFSETOF(struct S, c2));//4
//	printf("%d\n", OFFSETOF(struct S, c3));//8
//
//	printf("%d\n", sizeof(struct S));
//
//
//
//	return 0;
//}

//#include<stdio.h>
//
////打印箭形图案
//
//int main()
//{
//	int i,j,n = 0;
//
//	while (scanf("%d", &n) == 1)
//	{
//		//打印上n行
//
//		for (i = 0; i <= n - 1; i++)
//		{
//			for (j = 0; j < n - i; j++)
//			{
//				printf("  ");
//			}
//
//			for (j = 0; j <= i; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//
//		//打印n+1行
//		for (i = 0; i <= n + 1; i++)
//		{
//			for (j = 0; j < i; j++)
//			{
//				printf("  ");
//			}
//
//			for (j = 0; j < n + 1 - i; j++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//
//		if (n == 0)
//		{
//			return 0;
//		}
//	}
//
//
//
//
//
//	return 0;
//}

#include<stdio.h>

int main()
{
    int max = 0;
    int min = 0;
    int sum = 0;
    int scoer = 0;
    int n = 0;

    while(scanf("%d", &scoer) != EOF)
   {	n++;
    if (scoer > max)
        max = scoer;
    if (scoer < min)
        min = scoer;
    sum += scoer;
    if (n == 7)
    {
        printf("%.2f\n", (sum - max - min) / 5.0);
        sum = n = 0;
    }

   }


    return 0;
}