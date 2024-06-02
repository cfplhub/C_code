#include<iostream>
using namespace std;
#include<list>
#include<string>

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}


	string m_Name;
	int m_Age;
	int m_Height;

};

bool comparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height < p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}


void test01()
{
	list<Person> L;
	Person p1("s11", 23, 166);
	Person p2("s12", 43, 156);
	Person p3("s13", 45, 178);
	Person p4("s14", 33, 172);
	Person p5("s15", 23, 190);
	Person p6("s16", 23, 175);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "  年龄：" << (*it).m_Age << "  身高：" << (*it).m_Height << endl;
	}

	cout << "--------------------------------------------------------------------------" << endl;
	L.sort(comparePerson);

	cout << "排序后：" << endl;

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "  年龄：" << (*it).m_Age << "  身高：" << (*it).m_Height << endl;
	}

}

int main()
{


	test01();


	system("pause");
	return 0;
}