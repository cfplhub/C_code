#include<stdio.h>
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	

	while (left <= right)
	{
		int mid = (left + (right - left)) / 2;
		
		if (arr[mid] > k)
		{
			right = mid - 1;
		}

		if (arr[mid] < k)
		{
			left = mid + 1;
		}

		else
		{
			return mid;
		}
	}

	return -1;
}

int main()
{

	
	int i, k, sz;

	k = 7;

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	sz = sizeof(arr) / arr[0];

	int ret = binary_search(arr, k, sz);

	printf("%d\n",ret);

	if (ret==-1)
	{
		printf("没找到！\n");
		printf("hhhhhh\n");
	}

	else
	{
		printf("找到了，下标为：%d",ret);
	}


	return 0;
}