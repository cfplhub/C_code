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
    int a = 1; // 쳲��������еĵ�1��
    int b = 1; // 쳲��������еĵ�2��
    int c = 0;

    scanf("%d", &n);

    if (n == 1 || n == 2) // ֱ�Ӵ���nΪ1��2���������
    {
        printf("%d\n", a);
    }
    else
    {
        while (b < n) // ��bС��nʱ����ѭ��
        {
            c = a + b; // �����µ�쳲�������
            a = b;     // ����aΪb��ֵ
            b = c;     // ����bΪ�µ�쳲�������
        }
        printf("%d\n", b); // ���쳲��������еĵ�n��
    }

    return 0;
}