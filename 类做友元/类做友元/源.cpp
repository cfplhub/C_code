#include<iostream>
using namespace std;

class Building {
	friend class Goodgay;
public:
	Building();

public:
	string m_sistingroom;
private:
	string m_bedroom;
};

class Goodgay
{
public:

	Goodgay();
	void visit();
	Building * building;
};

Building::Building()
{
	m_sistingroom = ("����");
	 m_bedroom = ("����");

}

Goodgay::Goodgay()
{
	building = new Building;
}


void Goodgay::visit()
{
	cout << "�û������ڷ��ʣ�" << building->m_sistingroom << endl;
	cout << "�û������ڷ��ʣ�" << building->m_bedroom << endl;
}

void test01()
{
	Goodgay gg;
	gg.visit();
}

int main() {

	test01();

	system("pause");
	return 0;
}