#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

class Person
{
public:

	Person() {};

	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}


	string m_Name;
	int m_Score;

};

void Creatperson(vector<Person>& v)
{	
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		
		string name = "²ÌÐìÀ¤";
		name += nameseed[i];

		int score = 0;
		Person p(name,score);
		v.push_back(p);
	}


}


//class Myprint1
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};


void setScore(vector<Person>& v)
{
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;

		for (int i = 0; i < 10; i++)
		{

			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_front();
		d.pop_back();

		int sum = accumulate(d.begin(), d.end(),0);

		int avg = sum / d.size();

		it->m_Score = avg;

	}
		
}
	
void show(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ÐÕÃû£º" << it->m_Name << " µÃ·Ö£º" << it->m_Score << endl;
	}
}

int main()
{
	srand(time(nullptr));

	Person p;
	vector<Person>v;

	
	Creatperson(v);

	setScore(v);

	show(v);

	system("pause");
	return 0;
}


