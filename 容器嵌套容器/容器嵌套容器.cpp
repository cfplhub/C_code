#include<iostream>
using namespace std;
#include<vector>

//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	vector<int>v4;
//	for (int i = 0; i < 4; i++)
//	{
//		
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//
//	vector<vector<int>>v;
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator vit = (*it).begin();vit!=(*it).end();vit++)
//		{
//			cout << (*vit)<<"  ";
//		}
//		cout << endl;
//	}
//}

//vectorÔ¤Áô¿Õ¼ä
void test02()
{
	vector<int> v;
	
	int num = 0;
	int* p = NULL;
	v.reserve(10000);

	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
		
	}
	cout << "num= " << num << endl;
}



int main()
{
	//test01();

	test02();

	system("pause");
	return 0;
}