#include <iostream>
using namespace std;

class person
{
public:
	person(int a)
	{
		this->a =  a;
	}

	

	person& addperson(person &p)
	{
		this->a += p.a;

		return *this;
	}
	
	int a;

};



void test01()
{
	person p(10);
	cout << "a=" <<p.a<< endl;
}

void test02()
{
	person p(10);
	person p2(50);

	p2.addperson(p).addperson(p).addperson(p);

	cout << "a=" << p2.a << endl;
}

int main()
{
	test01();
	test02();
	

	

	system("pause");
	return 0;
}