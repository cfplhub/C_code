#include<iostream>
using namespace std;

//冒泡排序函数  参数1  数组的首地址   参数2  数组的长度
void bubblesort(int* arr, int len);

void bubblesort(int* arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}

	}
}

	void printArray(int* arr, int len);
	
	//打印数组
	void printArray(int* arr, int len)
	{
		for (int i = 0; i < len; i++)
		{
			cout << arr[i] << endl;
		}
	}


int main() {

	//创建数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	int len = sizeof(arr) / sizeof arr[0];

	//创建函数，实现冒泡顺序
	bubblesort(arr, len);

	printArray(arr, len);

	 



	system ("pause");
	return 0;

}