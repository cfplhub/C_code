#include<iostream>
using namespace std;
#include<set>
#include<string>

class Mycompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it<<"  ";
	}

	cout << endl;
	

	set<int,Mycompare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

}

int main()
{

	test01();



	system("pause");
	return 0;
}