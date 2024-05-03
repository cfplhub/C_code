#include<iostream>
using namespace std;

class bass
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son :public bass
{
	int m_d;
};

//利用上面工具 命令行 开发者命令提示
//跳转盘符 C:
//跳转文件途径 cd 具体途径下
//查看命名
//cl d1 reportSingleClassLayout类名 文件名("源.cpp")

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}