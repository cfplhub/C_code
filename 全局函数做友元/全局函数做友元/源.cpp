#include<iostream>
using namespace std;
#include<string>

class Building
{
	friend void goodfriend(Building &building);
public:
	Building()
	{
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}

public:
	string m_sittingroom;

private:

	string m_bedroom;

};

void goodfriend(Building &building)
{
	
	cout << "好朋友正在全局函数访问：" << building.m_sittingroom << endl;
	cout << "好朋友正在全局函数访问：" << building.m_bedroom << endl;
}

void test01()
{
	Building building;
	goodfriend(building);
}


int main() {

	test01();

	system("pause");
	return 0;
}