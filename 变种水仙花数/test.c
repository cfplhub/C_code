#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<math.h>

//变种水仙花数即
//eg: 1344 = 1 * 344 + 13 * 44 + 134 * 1;
//eg: 156  = 1 * 56 + 15 * 6;  结果成立即为变种水仙花数

int main()

{
	int i = 0, j = 0;

	for (i = 10000; i < 99999; i++)
	{
		int sum = 0;
		for (j = 1; j <= 4; j++)
		{
			int k = (int)pow(10, j);
			sum += (i / k) * (i % k);
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}

	//int i, j = 0;

	//for (i = 0; i < 9; ++i)
	//{
	//	printf("%d ", i);
	//}

	return 0;
}