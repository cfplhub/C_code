#include<iostream>
using namespace std;
#include<fstream>

void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "�������½�����??" << endl;
	ofs << "���䣺26" << endl;
	ofs << "���ԣ���" << endl;
	ofs << "��ɫ����" << endl;
	ofs.close();



}



int main()  
{

	test01();



	system("pause");
	return 0;
}