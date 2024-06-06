#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
#include<list>

class Person
{
public:
	Person(string name, int age)
	{
		this->Name = name;
		this->Age = age;
	}

	string Name;
	int Age;
};

void Print(int val)
{
	cout << val << endl;
}


void test()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person> ::iterator it = v.begin(); it != v.end(); it++)
	{
		cout <<"姓名："<<(*it).Name<<" 年龄："<<(*it).Age << endl;
	}

	//for_each(v.begin(), v.end(), Print);
}

void test02()
{
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*> ::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->Name << " 年龄：" << (*it)->Age << endl;
	}


	vector<int> v1;
	v1.push_back(110);
	v1.push_back(120);
	v1.push_back(130);
	v1.push_back(140);
	v1.push_back(150);

	for_each(v1.begin(), v1.end(), Print);
}

void test03()
{
	list<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	a.push_back(6);
	a.push_back(5);
	for_each(a.begin(), a.end(), Print);
}

int main()
{
	//test();

	//test02();

	test03();

	system("pause");
	return 0;
}