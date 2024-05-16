#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//打印杨辉三角
//int main()
//{
//	int arr[10][10] = { 0 };
//
//	int i, j= 0;
//
//	for (i = 0; i <10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j ==0)
//			{
//				arr[i][j] = 1;
//			}
//
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{	
//		for (j = 0;j <= i; j++)
//		{
//			printf("%3d", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//实现一个函数，可以实现左旋转K个字符
//void left_rotate(char arr[], int k)
//{
//	int i = 0;
//	int len = (int)strlen(arr);
//
//	//if (k == len)
//	//{
//	//	return 1;
//	//}
//	//else if (k > len)
//	//{
//	//	k = k - len;
//	//}
//
//	k %= len;
//
//	for (i = 0; i < k; i++)
//	{
//		char temp = arr[0];
//		int j = 0;
//
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = temp;
//	}
//}

//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_rotate(char arr[], int k)
//{
//	int len = (int)strlen(arr);
//	k %= len;
//
//	//左
//	reverse(arr,arr + k - 1);
//	//右
//	reverse(arr + k, arr + len - 1);
//	//整体
//	reverse(arr, arr + len - 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//
//	printf("请输入旋转值k:");
//	scanf("%d", &k);
//
//	left_rotate(arr, 2);
//
//	printf("%s", arr);
//
//
//
//	return 0;
//}

//杨氏矩形 ->  从左到右，上到下逐渐递增
//  1  2  3
//  4  5  6
//  7  8  9

/*

*     1   2   3
* 
*     4   5   6
* 
*     7   8   9
* 
* 
* 
*/

//struct  Point
//{
//	int x;
//	int y;
//
//};

//struct Point find_num(char arr[3][3], int r, int w, int k)
//{
//	int x = 0;
//	int y = w - 1;
//	struct Point p;
//	p.x = -1;
//	p.y = -1;
//	while (y >= 0 && x <= r - 1)
//	{
//		if (k < arr[x][y])
//		{
//			y--;
//		}
//		else if (k > arr[x][y])
//		{
//			x++;
//		}
//		else
//		{
//			p.x = x;
//			p.y = y;
//			//printf("下标为：%d   %d\n", x, y);
//			return p;
//		}
//	}
//	return  p;
//}

int find_num(char arr[3][3], int* px, int* py, int k)
{
	int x = 0;
	int y = *py - 1;

	while (y >= 0 && x <= *px - 1)
	{
		if (k < arr[x][y])
		{
			y--;
		}
		else if (k > arr[x][y])
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			//printf("下标为：%d   %d\n", x, y);
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return  0;
}

int main()
{
	char arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	printf("请输入你要查找的数->  ");

	int k;

	int x = 3;//行

	int y = 3;//列

	scanf("%d", & k);

	int ret = find_num(arr, &x, &y, k);

	if (ret == 1)

		printf("%d   %d\n", x, y);
	else
		printf("找不到\n");

	return 0;
}