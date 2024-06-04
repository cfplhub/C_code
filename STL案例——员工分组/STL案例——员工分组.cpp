#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
#define CHEHUA 0
#define YANFA  1
#define MEISHU 2
using namespace std;

class Worker
{
public:
	Worker() {};
	Worker(string name, int salary)
	{
		this->m_Name = name;
		this->m_Salary = salary;
	}

	string m_Name;
	int m_Salary;
};

void createworker(vector<Worker>& v)
{
	
	string nameseed = "ABCDEFGHIJ";
	
		for (int i = 0; i < 10; i++)
		{
			Worker worker;
			worker.m_Name = "员工";
			worker.m_Name += nameseed[i];
			worker.m_Salary = rand() % 10000 + 10000;
			v.push_back(worker);
		}

	
}

void setGourp(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int Indept = rand() % 3;
		m.insert(make_pair(Indept, *it));
	}
}

void ShowGourp(multimap<int,Worker>&m)
{
	cout << "策划部门：" << endl;

	multimap<int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);
	int index = 0;

	for (; pos != m.end() && index < count; pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------------" << endl;
	cout << "研发部门：" << endl;

	
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;

	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}


	cout << "------------------------------------" << endl;
	cout << "美术部门：" << endl;

	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;

	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
}


void test01()
{
	vector<Worker>v;
	createworker(v);
	
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << "  工资:" << it->m_Salary << endl;
	//}
	//
	multimap<int, Worker>m;

	setGourp(v, m);

	
}

int main()
{
	//随机数种子
	//srand(time(nullptr));
	srand((unsigned int)time(NULL));
	
	//test01();

	vector<Worker>v;
	createworker(v);

	multimap<int, Worker>m;

	setGourp(v, m);

	ShowGourp(m);










	system("pause");
	return 0;
}