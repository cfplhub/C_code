#include<iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout << "person��Ĭ�Ϲ��캯������" << endl;
	}

	person(int age,int higher)
	{
		m_age = age;
		m_higher = new int (higher);
		cout << "person���вι��캯������" << endl;
	}

	person(const person& p)
	{
		cout << "person�Ŀ������캯������" << endl;
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
		cout << "person��������������" << endl;
	}



	int m_age;
	int *m_higher;

};

void text01()
{
	person p1(18,177);
	cout << "p1������Ϊ��" << p1.m_age << endl;
	cout << "p1�����Ϊ��" << *p1.m_higher << endl;

	person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << endl;
	cout << "p2�����Ϊ��" << *p2.m_higher << endl;
	

}


int main()
{
	text01();



	system("pause");
	return 0;
}