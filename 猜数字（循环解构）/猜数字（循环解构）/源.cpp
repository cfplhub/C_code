#include <iostream>
using namespace std;
#include<ctime>
int main() {

	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int val = 0;
	//cout << num << endl;

	cout << "请猜测一下数字" << endl;


	while (num!=val) {


		int val = 0;
		cin >> val;

	
	if (val > num) {

		cout << "猜大了" << endl;
	}

	else if (val < num) {

		cout << "猜小了" << endl;

	}
	else {

		cout << "恭喜您，猜对了" << endl;
		break;
			}

		

	}
		









	system("pause");
	return 0;
}