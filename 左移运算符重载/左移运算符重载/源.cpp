#include <iostream>
using namespace std;

class person
{
public:

	person(int a, int b)
	{
		m_a = a;
		m_b = b;
	}



	int m_a;
	int m_b;


};

ostream &operator<<(ostream &cout, person& p)
{
	cout << "m_a = " <<p.m_a<< "  m_b = " << p.m_b << endl;

	return cout;
}
void test()
{
	person p(10,10);

	cout<< p<<endl;
	
}
int main()
{
	test();

	system("pause");
	return 0;

}
