#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	//矩形转阵
//	//输入n行m列  -> 输出m行n列
//	//输入：  1  2  3
//	//        4  5  6
//	//输出：  1  4
//	//        2  5
//	//        3  6
//
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//
//	int arr[10][10] = { 0 };
//	int i, j = 0;
//
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//
//
//}

//int main()
//{
//	unsigned int num;
//	scanf("%d", &num);//1234
//
//	while (num)
//	{
//		printf("%d ", num % 10);
//
//		num / 10;
//	}
//
//	//打印结果为： 4 3 2 1
//
//	return 0;
//}

//void print(unsigned int x)
//{
//    if (x > 9)
//    {
//        print(x / 10);
//    }
//    printf("%d ", x % 10);
//}
//
//int main()
//{
//    unsigned int x = 0;
//
//    scanf("%d", &x);
//
//    print(x);
//
//
//    return 0;
//}


//int main()
//{
//    int a, b, c, tmp = 0;
//
//    //输入
//    scanf("%d %d %d", &a, &b, &c);
//
//    if (a < b)
//    {
//        tmp = a;
//        a = b;
//        b = tmp;
//    }
//
//    if (b < c)
//    {
//        tmp = c;
//        c = b;
//        b = tmp;
//    }
//
//    if (a < c)
//    {
//        tmp = a;
//        a = c;
//        c = tmp;
//    }
//    //输出
//    printf("%d %d %d", a, b, c);
//
//    return 0;
//}

//int main()
//{
//    int i = 0;
//
//    for (i = 1; i < 100; i++)
//    {
//        if (i % 3 == 0)
//        {
//            printf("%d ", i);
//        }
//    }
//
//
//    return 0;
//}

int main()
{
    int i = 0;

    for (i = 1000; i <= 2000; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            printf("%d  ", i);
        }
    }


    return 0;
}