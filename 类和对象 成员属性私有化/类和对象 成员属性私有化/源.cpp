#include<iostream>
using namespace std;

class person
{
public:
	void setname(string name)
	{
		m_name = name;
	}

	string getname()
	{
		return m_name;
	}

	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			m_age = 0;
			cout << "�������������" << endl;
			return ;
		}
		m_age = age;

	}

	int getage() {

		
		return m_age;
	}

	void setlover(string lover)
	{
		m_lover = lover;
	}

	

private:

	string m_name;
	int m_age;
	string m_lover;
};





int main() {

	person p;

	p.setlover("����");
	p.setname("ϲˢˢ");
	cout << "����Ϊ��" << p.getname() << endl;
	p.setage(18);
	cout << "���䣺" << p.getage() << endl;
	system("pause");
	return 0;
}