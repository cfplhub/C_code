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
	cout << "打印后：" << " 容器大小为：" << arr.getsize() << "  容量为：" << arr.getcapacity() << endl; 

	arr.popback(1);

	cout << "尾删后：" << " 容器大小为：" << arr.getsize() << "  容量为：" << arr.getcapacity() << endl;

	
	

	cout << "arr2的打印输出" << endl;
	Myarray <int>arr2(arr);
	PrintArray(arr2);

	cout << "------------"<<endl;
	Myarray <int>arr3(100);
	PrintArray(arr3);
	cout  << " 容器arr3的大小为：" << arr3.getsize() << "  容量为：" << arr3.getcapacity() << endl;

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
		cout <<"姓名："<< p[i].m_name <<"  年龄： " << p[i].age << endl;
	}
}

void test02()
{
	

	Myarray<Person>p(10);

	Person p1("张三", 21);
	Person p2("李希", 22);
	Person p3("蔡徐坤", 23);
	Person p4("鸡你太美", 31);

	p.pushback(p1);
	p.pushback(p2);
	p.pushback(p3);
	p.pushback(p4);


	Myprint2(p);

	//输出容量
	cout << "p容量为" << p.getcapacity() << endl;
	//输出大小
	cout << "p大小为" << p.getsize() << endl;
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}