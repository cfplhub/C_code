#include<iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}

	person(int age,int higher)
	{
		m_age = age;
		m_higher = new int (higher);
		cout << "person的有参构造函数调用" << endl;
	}

	person(const person& p)
	{
		cout << "person的拷贝构造函数调用" << endl;
		m_age = p.m_age;

		m_higher = new int(*p.m_higher);
	}

	~person()
	{
		if (m_higher != NULL)
		{
			delete m_higher;
			m_higher = NULL;
		}
		cout << "person的析构函数调用" << endl;
	}



	int m_age;
	int *m_higher;

};

void text01()
{
	person p1(18,177);
	cout << "p1的年龄为：" << p1.m_age << endl;
	cout << "p1的身高为：" << *p1.m_higher << endl;

	person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << endl;
	cout << "p2的身高为：" << *p2.m_higher << endl;
	

}


int main()
{
	text01();



	system("pause");
	return 0;
}