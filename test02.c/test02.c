#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define PI 3.14
//
//int main()
//{
//	printf("��ӭʹ��C����������ȥ��·��������Զ��\n");
//
//	float r, f;
//
//	scanf("������Բ�İ뾶��%f\n", &r);
//
//	f = PI * r * r;
//
//	scanf("Բ�����Ϊ%f", f);
//
//	return 0;
//}


#include<stdio.h>
#define PI 3.14159

int main()
{
    printf("��ӭʹ��C����������ȥ��·��������Զ��\n");

    float r, f;

    printf("������Բ�İ뾶��");
    scanf("%f", &r);

    f = PI * r * r;

    printf("Բ�����Ϊ:%f\n", f);

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