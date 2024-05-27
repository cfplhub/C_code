#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i < 100; i++) {

		if (i % 10 == 8 || i / 10 ==  8  || i % 8== 0) {
			cout << "ÇÃ×À×Ó" << endl;

		}
		else {
			cout << i << endl;
		}
	}


	system("pause");
	return 0;
}