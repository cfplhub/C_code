#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<ctime>


class Myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};


void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>v3;

	v3.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	cout << "数组v1为：" << endl;
	for_each(v1.begin(), v1.end(), Myprint());
	cout << endl;

	cout << "--------" << endl;
	cout << "数组v2为：" << endl;
	for_each(v2.begin(), v2.end(), Myprint());
	cout << endl;

	cout << "两数组合计为：" << endl;
	for_each(v3.begin(), v3.end(),Myprint());

	cout << endl;

	

}


//随机调整数字random_shuffle

void test02()
{
	vector<int>v4;
	for (int i = 0; i < 10; i++)
	{
		v4.push_back(i);
	}

	random_shuffle(v4.begin(), v4.end());

	for_each(v4.begin(), v4.end(), Myprint());
	cout << endl;
}

//sort排序
void test03()
{
	vector<int>v5;
	for (int i = 0; i < 10; i++)
	{
		v5.push_back(i);
	}

	random_shuffle(v5.begin(), v5.end());

	
	sort(v5.begin(), v5.end());

	for_each(v5.begin(), v5.end(), Myprint());
	cout << endl;

	cout << "--------------------" << endl;
	cout << "改为降序：" << endl;

	sort(v5.begin(), v5.end(),greater<int>());

	for_each(v5.begin(), v5.end(), Myprint());
	cout << endl;
}

void test04()
{
	vector<int>v6;
	for (int i = 0; i < 6; i++)
	{
		v6.push_back(i);
	}

	cout << "反转前：" << endl;

	for_each(v6.begin(), v6.end(), Myprint());
	cout << endl;

	cout << "----------------" << endl;
	cout << "反转后：" << endl;

	reverse(v6.begin(), v6.end());

	for_each(v6.begin(), v6.end(), Myprint());
	cout << endl;

 }


int main()
{
	srand((unsigned int)time(NULL));

	
	test01();

	cout << "--------------------" << endl;
	cout << "打乱数组：" << endl;
	test02();

	cout << "--------------------" << endl;
	cout << "重新排列：" << endl;
	test03();


	cout << "--------------------" << endl;
	test04();


	system("pause");
	return 0;
}