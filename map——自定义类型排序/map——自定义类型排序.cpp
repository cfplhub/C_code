#include<iostream>
#include<map>
#include<string>
using namespace std;

void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << (*it).first << "  val= " << it->second << endl;
	}

}

class Person
{
public:

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;

	}

	string m_Name;
	int m_Age;


};

class Mycompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age > p2.m_Age;
	}
};


void test02()
{
	map<Person,int,Mycompare>m2;

	Person p1("ÕÔ·É", 23);
	Person p2("Ï¹·É", 33);
	Person p3("ºú·É", 24);
	Person p4("ÂÒ·É", 27);

	m2.insert(pair<Person, int>(p1, p1.m_Age));
	m2.insert(make_pair(p2, p2.m_Age));
	m2.insert(pair<Person, int>(p3, p3.m_Age));
	m2.insert(pair<Person, int>(p4, p4.m_Age));

	for (map<Person, int, Mycompare>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first.m_Name << "  val = " << it->second << endl;
	}

}


int main()
{

	test01();

	test02();


	system("pause");
	return 0;
}