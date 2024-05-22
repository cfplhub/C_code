#include<iostream>
using namespace std;

class person
{
public:
	person(int a,int b,int c):m_a(a),m_b( b),m_c(c)
	{
	}

	int m_a;
	int m_b;
	int m_c;
};

void text01()
{	
	person p(10, 23, 44);
	cout << "m_a=" << p.m_a << endl;
	cout << "m_b=" << p.m_b << endl;
	cout << "m_c=" << p.m_c << endl;
}
int main() {

	text01();
	system("pause");
	return 0;
}