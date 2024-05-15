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

class son :public bass
{
	int m_d;
};

void test01()
{
	cout << "sizeof son = " << sizeof(son) << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}