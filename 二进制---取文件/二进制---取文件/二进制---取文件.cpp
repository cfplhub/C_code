#include<iostream>
using namespace std;
#include<fstream>
#include<string>


class Person
{
public:

	char m_Name[64];
	int m_Age;

};


//������д�ļ�
void test01()
{
	ofstream ofs;

	ofs.open("Person.txt", ios::out | ios::binary);

	Person p = { "����",18 };

	ofs.write((const char*)&p, sizeof(p));

	ofs.close();

}



//�����ƶ��ļ�
void test02()
{
	ifstream ifs;

	ifs.open("Person.txt", ios::in | ios::binary);

	Person p;

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
	}

	ifs.read((char*)&p, sizeof(p));

	cout << "������" << p.m_Name << "  " << "���䣺" << p.m_Age << endl;

	ifs.close();



}



int main()
{


	test01();

	test02();

	system("pause");
	return 0;
}