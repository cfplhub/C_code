#include<iostream>
using namespace std;
#include<string>

class phone
{
public:
	phone(string PName)
	{
		m_PName = PName;
		
	}
	string m_PName;
};

class person
{
public:
	person(string name, string PName) :m_Name(name), m_Phone(PName)
	{

	}

	string m_Name;
	phone m_Phone;
};

void test01()
{
	person p("�°���", "��ΪMATE 50PRO");
	cout << p.m_Name << "����" << p.m_Phone.m_PName << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}