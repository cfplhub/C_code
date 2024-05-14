#include<iostream>
using namespace std;
//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择 
//测试 char 数组 int 数组
//交换的函数模板
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void Mysort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len ; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		if (min != i)
		{
			mySwap(arr[min], arr[i]);
		}
	}
}

template<class T>
void print(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test01()
{
	char arry[] = "bdecafihg";
	int num = sizeof(arry) / sizeof(char);
	Mysort(arry, num);
	print(arry, num);
}

void test02()
{
	int arry[] = { 9,3,6,7,5,8,2,3,1 };
	int num = sizeof(arry) / sizeof(int);
	Mysort(arry, num);
	print(arry, num);
}

int main()
{

	test01();

	test02();

	system("pause");
	return 0;

}