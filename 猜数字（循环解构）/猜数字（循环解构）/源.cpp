#include <iostream>
using namespace std;
#include<ctime>
int main() {

	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int val = 0;
	//cout << num << endl;

	cout << "��²�һ������" << endl;


	while (num!=val) {


		int val = 0;
		cin >> val;

	
	if (val > num) {

		cout << "�´���" << endl;
	}

	else if (val < num) {

		cout << "��С��" << endl;

	}
	else {

		cout << "��ϲ�����¶���" << endl;
		break;
			}

		

	}
		









	system("pause");
	return 0;
}