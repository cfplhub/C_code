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
			cout << "你这个老妖精！" << endl;
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

	p.setlover("张三");
	p.setname("喜刷刷");
	cout << "姓名为：" << p.getname() << endl;
	p.setage(18);
	cout << "年龄：" << p.getage() << endl;
	system("pause");
	return 0;
}