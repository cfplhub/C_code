#include<iostream>
#include<string>
using namespace std;

class Myadd
{
public:
	int operator()(int val1, int val2)
	{
		return val1 + val2;
	}
};

class Myprint
{
public:

	Myprint()
	{
		this->count = 0;
	}

	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}

	int count;
};

void doWork(Myprint& m, string test)
{
	m(test);
}

void test01()
{
	Myadd myadd;
	cout << myadd(10, 10) << endl;

	Myprint m;
	m("hello world");
	m("hello world");
	m("hello world");
	m("hello world");
	cout << "函数运算次数：" << m.count << endl;

	doWork(m, "hello C++");
}


int main()
{

	test01();



	system("pause");
	return 0;
}