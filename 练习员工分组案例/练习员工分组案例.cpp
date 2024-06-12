#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
#include<algorithm>
#define CHEHUA 0 
#define MEISHU 1 
#define YANFA 2 

using namespace std;

void Myprint(int val)
{
	cout << val << " ";
}

class Worker
{
public:
	Worker() {};
	Worker(string name, int salary)
	{
		this->m_name = name;
		this->m_salary = salary;
	}

	string m_name;
	int m_salary;
};

void Creatworker(vector<Worker>& v)
{
	string nameseed = "ABCDEFGHIJ";
	
	
	for (int i = 0; i < 10; i++)
	{
		Worker w;
		w.m_name = "Ա��";
		w.m_salary = rand()%10000+10000;
		w.m_name += nameseed[i];

		v.push_back(w);

	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int dept = rand() % 3;
		m.insert(make_pair(dept, *it));
	}
}

void show(multimap<int, Worker>& m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int,Worker>::iterator pos = m.find(0);
	int count = m.count(0);
	int dex = 0;

	for (; pos != m.end() && dex < count; pos++ , dex++)
	{
		cout << "������" << pos->second.m_name << "  ���ʣ�" << pos->second.m_salary << endl;
	}

	cout << "----------------------------" << endl;
	cout << "�������ţ�" << endl;
	pos = m.find(1);
	count = m.count(1);
	dex = 0;

	for (; pos != m.end() && dex < count; pos++, dex++)
	{
		cout << "������" << pos->second.m_name << "  ���ʣ�" << pos->second.m_salary << endl;
	}


	cout << "----------------------------" << endl;
	cout << "�з����ţ�" << endl;
	pos = m.find(2);
	count = m.count(2);
	dex = 0;

	for (; pos != m.end() && dex < count; pos++, dex++)
	{
		cout << "������" << pos->second.m_name << "  ���ʣ�" << pos->second.m_salary << endl;
	}
}

void test01()
{
	srand((unsigned int)time(NULL));
	Worker w;
	vector<Worker>v;

	Creatworker(v);

	multimap<int, Worker> m;

	setGroup(v, m);

	show(m);
}



int main()
{
	test01();
	



	system("pause");
	return 0;
}