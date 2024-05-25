#include<iostream>
using namespace std;
#include"myarray2.hpp"
#include<string>

void printIntarray(Myarray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	Myarray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		arr1.PushBack(i);
	}

	cout << "arr1的打印输出" << endl;
	printIntarray(arr1);
	cout << "arr1的容量为" << arr1.getcapacity() << endl;
	cout << "arr1的大小为" << arr1.getSize() << endl;
	
	
	
	cout << "arr2的打印输出" << endl;

	Myarray<int> arr2(arr1);
	printIntarray(arr2);

	cout << "arr2尾删后" << endl;

	arr2.PopBack();

	cout << "arr2的容量为" << arr2.getcapacity() << endl;
	cout << "arr2的大小为" << arr2.getSize() << endl;

	
}

class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
public:
	string m_name;
	int m_age;
};

void printarray(Myarray<Person> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_name << "  年龄：" << arr[i].m_age << endl;
	}
}

void test02()
{
	Myarray<Person> arr1(10);

	
	Person p1("伞兵1", 21);
	Person p2("伞兵2", 22);
	Person p3("伞兵3", 23);
	Person p4("伞兵4", 24);
	Person p5("伞兵5", 25);

	arr1.PushBack(p1);
	arr1.PushBack(p2);
	arr1.PushBack(p3);
	arr1.PushBack(p4);
	arr1.PushBack(p5);

	printarray(arr1);

	//输出容量
	cout << "arr容量为" << arr1.getcapacity() << endl;
	//输出大小
	cout << "arr大小为" << arr1.getSize() << endl;
	
}
	
	



int main()
{

	test01();
	test02();
	
	system("pause");
	return 0;
}