#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	int mid = 0;
	printf("������0~10���ֲ����±���> ");
	scanf("%d", &k);

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid]<k)
		{
			left = mid+1;
		}

		if (arr[mid] > k)
		{
			right = mid - 1;
		}

		else
		{
			break;
		}
	}

	if (left <= right)
	{
		printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
		
	}
	else
	{
		printf("�Ҳ�����\n");
	}

	return 0;

}