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


//二进制写文件
void test01()
{
	ofstream ofs;

	ofs.open("Person.txt", ios::out | ios::binary);

	Person p = { "张三",18 };

	ofs.write((const char*)&p, sizeof(p));

	ofs.close();

}



//二进制读文件
void test02()
{
	ifstream ifs;

	ifs.open("Person.txt", ios::in | ios::binary);

	Person p;

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
	}

	ifs.read((char*)&p, sizeof(p));

	cout << "姓名：" << p.m_Name << "  " << "年龄：" << p.m_Age << endl;

	ifs.close();



}



int main()
{


	test01();

	test02();

	system("pause");
	return 0;
}