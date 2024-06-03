#include<iostream>
using namespace std;
#include<string>
#include<set>

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

class ComparePerson
{
public:
	bool operator()(const Person& P1, const Person& P2)const
	{
		return P1.m_Age < P2.m_Age;
	}
};


void test01()
{
	set < Person,ComparePerson>s1;

	Person p1("ÕÔ·É", 23);
	Person p2("Ï¹·É", 33);
	Person p3("ºú·É", 24);
	Person p4("ÂÒ·É", 27);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);


	for (set<Person, ComparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout <<"ĞÕÃû: "<< it->m_Name << "  ÄêÁä£º " << it->m_Age << endl;
	}

}


int main()
{
	test01();


	system("pause");
	return 0;
}