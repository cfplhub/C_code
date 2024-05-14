#include<iostream>
using namespace std;
//ʵ��ͨ�� �������������ĺ���
//���� �Ӵ�С
//�㷨 ѡ�� 
//���� char ���� int ����
//�����ĺ���ģ��
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