#include<iostream>
using namespace std;
#include<string>

class Calculator
{
public:

	int getresult(string oper)
	{
		if (oper=="+")
		{
			return m_Num1 + m_Num2;
		}

		else if (oper=="-")
		{
			return m_Num1 - m_Num2;
		}

		else if (oper=="*")
		{
			return m_Num1 * m_Num2;
		}
	}



	int m_Num1;
	int m_Num2;
};

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;

	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getresult("+") << endl;

	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getresult("*") << endl;

	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getresult("-") << endl;


}

class chouxiangCalculator
{

public:

	virtual int getesult()
	{
		return 0;
	}


	int m_Num1;
	int m_Nmu2;

};


class addCalculator: public chouxiangCalculator
{
public:

	int getesult()
	{
		return m_Num1+m_Nmu2;
	}

};


class jianCalculator : public chouxiangCalculator
{
public:

	int getesult()
	{
		return m_Num1 - m_Nmu2;
	}


};

class chenCalculator : public chouxiangCalculator
{
public:

	virtual int getesult()
	{
		return m_Num1 * m_Nmu2;
	}


};

void test02()
{
	chouxiangCalculator* abc = new addCalculator;

	abc->m_Num1 = 300;
	abc->m_Nmu2 = 200;
	cout << abc->m_Num1 << " + " << abc->m_Nmu2 << " = " << abc->getesult() << endl;

	delete abc;

	abc = new jianCalculator;

	abc->m_Num1 = 300;
	abc->m_Nmu2 = 200;
	cout << abc->m_Num1 << " - " << abc->m_Nmu2 << " = " << abc->getesult() << endl;

	delete abc;

	abc = new chenCalculator;

	abc->m_Num1 = 300;
	abc->m_Nmu2 = 200;
	cout << abc->m_Num1 << " * " << abc->m_Nmu2 << " = " << abc->getesult() << endl;

	delete abc;

}

int main()
{


	test01();

	test02();



	system("pause");
	return 0;
}