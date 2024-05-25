#include<iostream>
using namespace std;
#include<string>

template<class Nametype=string, class Agetype=int >
class person
{
public:

	person(Nametype name, Agetype age)
	{
		this->Name = name;
		this->Age = age;
	}

	void Print()
	{
		cout << this->Name << "µÄÄêÁäÎª£º" << this->Age << endl;
	}

	Nametype Name;
	Agetype  Age;
};


void test01()
{
	person<> p("ËïÎò¿Õ", 999);

	p.Print();



}




int main()
{

	test01();


	system("pause");
	return 0;
}