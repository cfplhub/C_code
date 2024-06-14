#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


class Greatfive
{
public:
	bool operator()(int v1)
	{
		return  v1 > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>:: iterator it = find_if(v.begin(), v. end(), Greatfive());

	if (it == v.end())
	{
		cout << "未找到！" << endl;
	}

	else
	{
		cout << "找到了！" << endl;
		cout << *it << endl;
	}
}


class Mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}

};

//二元谓词
void test02()
{
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(30);

	sort(v1.begin(), v1.end());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	cout << "-------------------------" << endl;


	//sort(v1.begin(), v1.end(), Mycompare());
	//内建关系函数(关系仿函数)
	sort(v1.begin(), v1.end(), greater<int>());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	
	cout << endl;

}


int main()
{

	test01();

	test02();

	system("pause");
	return 0;
}