#include<iostream>
#include"MyArray.hpp"
#include<string>
using namespace std;

void PrintArry(MyArry <int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test01()
{
	MyArry <int>arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.PushBack(i);
	}

	cout << "arr1�Ĵ�ӡ���" << endl;
	PrintArry(arr1);
	cout << "arr1������Ϊ" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ" << arr1.getSize() << endl;


	cout << "arr2�Ĵ�ӡ���" << endl;
	MyArry <int>arr2(arr1);
	PrintArry(arr2);

	//βɾ
	arr2.PopBack();
	cout << "arr2βɾ��" << endl;
	cout << "arr2������Ϊ" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ" << arr2.getSize() << endl;

	/*MyArry<int>arr3(100);

	arr3 = arr1;*/

}





//�����Զ����������� 
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void PrintPersonArry(MyArry<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "����" << arr[i].m_Name << "����" << arr[i].m_Age << endl;
	}
}

void test02()
{
	MyArry<Person>arr(10);
	Person p1("ɡ��1", 21);
	Person p2("ɡ��2", 22);
	Person p3("ɡ��3", 23);
	Person p4("ɡ��4", 24);
	Person p5("ɡ��5", 25);

	//�����ݲ��뵽������
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	//��ӡ����
	PrintPersonArry(arr);
	//�������
	cout << "arr����Ϊ" << arr.getCapacity() << endl;
	//�����С
	cout << "arr��СΪ" << arr.getSize() << endl;
}


int main(void)
{
	test01();
	test02();
	system("pause");
	return 0;
}

