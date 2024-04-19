#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;


	for (int i = 0; i < 100000; i++)
	{
		int n = 1;
		int sum = 0;
		int temp = i;
		while (temp / 10)
		{
			n++;
			temp /= 10;
		}

		temp = i;
	
		while (temp)
		{

			sum += pow(temp % 10, n);

			temp /= 10;

		}

		if (sum == i)
		{
			printf("%d ", i);
		}

	}


	return 0;
}