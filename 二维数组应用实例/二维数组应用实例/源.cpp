#include<iostream>
using namespace std;
int main() {

	int scores[3][4] =
	{
		{100,100,100,55},
		{90,50,100,45},
		{60,70,80,47},
	};

	string names[3] = { "����","����","����" };

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "ͬѧ�ܳɼ�Ϊ�� " << sum << endl;
	}

	system("pause");

	return 0;
}