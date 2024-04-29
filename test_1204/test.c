#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int is_prime(n)
{
	int j;

	for (j = 2; j <= sqrt(n); j++)
	{
		if (n % j == 0)
		{
			return 0;
		}

	}

	return 1;

}

int main()
{
	int i;
	int count = 0;

	for (i = 101; i <= 200; i += 2)
	{
		if (is_prime(i))
		{
			printf("%d ", i);
			count++;
		}


	}

	printf("\ncount=%d", count);


	return 0;

}



//int main()
//{
//	int i ;
//	int count = 0;
//
//	for (i = 101; i <= 200; i+=2)
//	{
//		int j;
//
//		int flag = 1;
//
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//
//		}
//
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//
//	}
//
//	printf("\ncount=%d", count);
//
//
//	return 0;
//
//}