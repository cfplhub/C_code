//�����������������
#include<iostream>
using namespace std;
#include<string>

class person
{

public:

	void operator()(string test)
	{
		cout << test << endl;
	}

};

void p2(string test)
{
	cout << test << endl;
}



void test01()
{
	person p;
	p("������������ص���");

	person p2;
	p2("��������");

}

class Myadd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};


void test02()
{
	Myadd myadd;
	int ret = myadd(100, 200);
	cout << "ret = " << ret << endl;

	cout << Myadd()(100, 300) << endl;
}




int main()
{
	test01();
	test02();
	

	system("pause");
	return 0;
}