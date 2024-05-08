#include<iostream>
using namespace std;
//重载递增运算符
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载++运算符——前置
	//返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		++m_Num;
		return *this;
	}
	//重载++运算符——后置
	MyInteger operator++(int)//这个int在这里作为占位参数，用来区分前置递增和后置递增
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
		//后置递增要返回值，因为如果返回引用，这里相当于返回的是一个局部对象的引用。
		//局部对象在当前函数执行完毕之后就被释放掉了，还要返回引用就是非法操作。
	}
private:
	int m_Num;
};
//全局函数重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
void test()
{
	MyInteger myint;
	cout << ++(++myint);
	cout << myint;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main(void)
{
	//test();
	test02();
	system("pause");
	return 0;
}

