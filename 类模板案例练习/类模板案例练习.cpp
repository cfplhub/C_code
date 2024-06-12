#include<iostream>
using namespace std;
#include<string>
#include"Myarray.hpp"

void PrintArray(Myarray<int>&arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void test01()
{
	Myarray<int>arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr.pushback(i);
	}

	PrintArray(arr);
	cout << "��ӡ��" << " ������СΪ��" << arr.getsize() << "  ����Ϊ��" << arr.getcapacity() << endl; 

	arr.popback(1);

	cout << "βɾ��" << " ������СΪ��" << arr.getsize() << "  ����Ϊ��" << arr.getcapacity() << endl;

	
	

	cout << "arr2�Ĵ�ӡ���" << endl;
	Myarray <int>arr2(arr);
	PrintArray(arr2);

	cout << "------------"<<endl;
	Myarray <int>arr3(100);
	PrintArray(arr3);
	cout  << " ����arr3�Ĵ�СΪ��" << arr3.getsize() << "  ����Ϊ��" << arr3.getcapacity() << endl;

}

class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_name = name;
		this->age = age;
	}


	string m_name;
	int age;
};

void Myprint2(Myarray<Person>& p)
{
	for (int i = 0; i < p.getsize(); i++)
	{
		cout <<"������"<< p[i].m_name <<"  ���䣺 " << p[i].age << endl;
	}
}

void test02()
{
	

	Myarray<Person>p(10);

	Person p1("����", 21);
	Person p2("��ϣ", 22);
	Person p3("������", 23);
	Person p4("����̫��", 31);

	p.pushback(p1);
	p.pushback(p2);
	p.pushback(p3);
	p.pushback(p4);


	Myprint2(p);

	//�������
	cout << "p����Ϊ" << p.getcapacity() << endl;
	//�����С
	cout << "p��СΪ" << p.getsize() << endl;
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}