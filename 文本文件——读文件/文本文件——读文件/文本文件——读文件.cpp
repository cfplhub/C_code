#include<iostream>
using namespace std;
#include<fstream>
#include<string>

void test02()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "姓名：陈杰鑫乌??" << endl;
	ofs << "年龄：26" << endl;
	ofs << "属性：猪" << endl;
	ofs << "肤色：乌" << endl;
	ofs.close();



}


void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//方法一
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//方法二
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//方法三
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	////方法四
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