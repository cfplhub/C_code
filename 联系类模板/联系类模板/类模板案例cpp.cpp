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

	cout << "arr1�Ĵ�ӡ���" << endl;
	printIntarray(arr1);
	cout << "arr1������Ϊ" << arr1.getcapacity() << endl;
	cout << "arr1�Ĵ�СΪ" << arr1.getSize() << endl;
	
	
	
	cout << "arr2�Ĵ�ӡ���" << endl;

	Myarray<int> arr2(arr1);
	printIntarray(arr2);

	cout << "arr2βɾ��" << endl;

	arr2.PopBack();

	cout << "arr2������Ϊ" << arr2.getcapacity() << endl;
	cout << "arr2�Ĵ�СΪ" << arr2.getSize() << endl;

	
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
		cout << "������" << arr[i].m_name << "  ���䣺" << arr[i].m_age << endl;
	}
}

void test02()
{
	Myarray<Person> arr1(10);

	
	Person p1("ɡ��1", 21);
	Person p2("ɡ��2", 22);
	Person p3("ɡ��3", 23);
	Person p4("ɡ��4", 24);
	Person p5("ɡ��5", 25);

	arr1.PushBack(p1);
	arr1.PushBack(p2);
	arr1.PushBack(p3);
	arr1.PushBack(p4);
	arr1.PushBack(p5);

	printarray(arr1);

	//�������
	cout << "arr����Ϊ" << arr1.getcapacity() << endl;
	//�����С
	cout << "arr��СΪ" << arr1.getSize() << endl;
	
}
	
	



int main()
{

	test01();
	test02();
	
	system("pause");
	return 0;
}