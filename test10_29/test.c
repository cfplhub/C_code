#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	int left = 0;

	int right = sz - 1;

	int mid = 0;

	int k = 0;

	printf("请输入数字（0~10）\n");

	scanf("%d", &k);

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}

		else if (arr[mid] > k)
		{
			right = mid - 1;
		}

		else
		{
			printf("找到了,数值为：%d\n",arr[mid]);
			break;
		}

	}

        if (left > right)
		{
			printf("找不到\n");
		}

	return 0;

}