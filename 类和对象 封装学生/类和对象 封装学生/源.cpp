#include<iostream>
using namespace std;
#include<string>
class student
{
public:
	string m_name;
	int m_id;

	void showstudent() {
	
		cout << "学生的姓名为：" << m_name <<"\t "<<"学号为：" << m_id << endl;

	}
	void setname(string name)
	{
		m_name = name;
	}

	void setid(int id)
	{
		m_id = id;
	}
};

int main() {

	
	student s1;
	s1.setname ("张三");
	s1.setid (1);
	
	student s2;
	s2.setname ("老才");
	s2.setid(9);

	s1.showstudent();
	s2.showstudent();
	system("pause");
	return 0;

}