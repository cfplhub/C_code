#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_score = score;
	}


	string m_Name;
	int m_score;
};

void creatperson(vector<Person>&v)
{
	
	string Nameseed = "ABCDE";
	

	for (int i = 0; i < 5; i++)
	{
		string name = "蔡徐坤";
		name += Nameseed[i];
		int score = 0;
		Person p(name, score);

		v.push_back(p);

	}

}

void setScore(vector<Person>&v)
{
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		
			cout << "姓名：" << it->m_Name << "  分数：" << endl;
			for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
			{
				cout << *dit<<"  ";
			}
			cout << endl;
		

		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();

		int sum = 0;
		for (deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			sum += *dit;
		}

		int avg = sum / d.size();
		it->m_score = avg;
	}
}

void showPerson(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it!= v.end(); it++)
	{
		cout << "姓名:" << it->m_Name << "  分数：" << it->m_score << endl;
	}

}


int main()
{
	srand((unsigned int)time(NULL));

	vector<Person>v;
	creatperson(v);
	setScore(v);

	showPerson(v);





	system("pause");
	return 0;
}