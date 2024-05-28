#include<iostream>
using namespace std;
int main() {
	

	for (int num = 100; num < 1000; num++) {

		int a = 0;
		int b = 0;
		int c = 0;

		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;


		if (num==a*a*a + b*b*b+ c*c*c)
			

		cout << num << endl;
	}

	system("pause");
	return 0;
}


