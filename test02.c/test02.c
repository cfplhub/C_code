#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define PI 3.14
//
//int main()
//{
//	printf("欢迎使用C程序，请坚持下去，路漫漫其修远兮\n");
//
//	float r, f;
//
//	scanf("请输入圆的半径：%f\n", &r);
//
//	f = PI * r * r;
//
//	scanf("圆的面积为%f", f);
//
//	return 0;
//}


#include<stdio.h>
#define PI 3.14159

int main()
{
    printf("欢迎使用C程序，请坚持下去，路漫漫其修远兮\n");

    float r, f;

    printf("请输入圆的半径：");
    scanf("%f", &r);

    f = PI * r * r;

    printf("圆的面积为:%f\n", f);

    int a = 10;
    int b = 20;
    int c;

    if (a > b)

        c = a;
    else
        c = b;

    printf("c=%d", c);



    return 0;
}