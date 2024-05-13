#include<iostream>
using namespace std;

class person
{
public:

	person(int age)
	{
		m_age = new int(age);
	}

	~person()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	person& operator=(person &p)
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}

		m_age = new int(*p.m_age);
		return *this;
	}


	int *m_age;

};

void test01()
{
	person p(18);

	person p2(20);

	person p3(30);

	p = p2 = p3;
	cout << "person p������Ϊ��" << *p.m_age << endl;
	cout << "person p2������Ϊ��" << *p2.m_age << endl;
	cout << "person p3������Ϊ��" << *p3.m_age << endl;
}

int main() {

	test01();


	system("pause");
	return 0;
}