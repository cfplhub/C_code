#include<iostream>
using namespace std;
#include<string>

class Building
{
	friend void goodfriend(Building &building);
public:
	Building()
	{
		m_sittingroom = "����";
		m_bedroom = "����";
	}

public:
	string m_sittingroom;

private:

	string m_bedroom;

};

void goodfriend(Building &building)
{
	
	cout << "����������ȫ�ֺ������ʣ�" << building.m_sittingroom << endl;
	cout << "����������ȫ�ֺ������ʣ�" << building.m_bedroom << endl;
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