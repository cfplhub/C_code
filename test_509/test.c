#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

//int main()
//{
//	//输入整数，其中对应整数的每个位，奇数设为1，偶数设为0
//
//	int input = 0;
//	int sum = 0;
//	scanf("%d", &input);
//	int i = 0;
//
//	while (input)
//	{
//
//		//int bit = input % 10;
//
//		//if (input % 2 == 1)
//		//{
//		//	sum += 1 * pow(10, i++ );
//		//}
//
//		//else
//		//{
//		//	sum += 0 * pow(10, i++ );
//		//}
//
//
//		int bit = input % 10;
//
//		if (bit % 2 == 1)
//		{
//			bit = 1;
//		}
//
//		else
//		{
//			bit = 0;
//		}
//
//		sum += bit * pow(10, i++);
//
//		input /= 10;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}

//int main()
//{
//	int n= 0 ;
//
//	while (scanf("%d", &n) == 1)
//	{
//		int i, j = 0;
//
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i + j < n - 1)
//				{
//					printf(" ");
//				}
//				else
//					printf("*");
//			}
//			printf("\n");
//		}
//
//	}
//   return 0;
// }

int main()
{
	unsigned char a = 100;//整形提升
	//0000 0000 0000 0000 0000 0000 0110 0100
	//0110 0100 -a 截断

	unsigned char b = 200;//整形提升
	//0000 0000 0000 0000 0000 0000 1100 1000
	//1100 1000 -b 截断

	unsigned char c;
	//0000 0000 0000 0000 0000 0000 0110 0100
	//0000 0000 0000 0000 0000 0000 1100 1000
	//0000 0000 0000 0000 0000 0001 0010 1100
	// 300
	//0010 1100 - c 截断  -> 44
	c = a + b;

	printf("%d %d\n", a + b, c);
	//300 44



	return 0;
}