#include<iostream>
using namespace std;
#include<fstream>
#include<string>

void test02()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "�������½�����??" << endl;
	ofs << "���䣺26" << endl;
	ofs << "���ԣ���" << endl;
	ofs << "��ɫ����" << endl;
	ofs.close();



}


void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//����һ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//������
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	////������
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	//ifs.close();


}







int main()
{

	test01();

	test02();

	system("pause");
	return 0;
}