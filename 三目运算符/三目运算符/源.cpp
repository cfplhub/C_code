#include<iostream>
using namespace std;
int main() {

	int a = 12;
	int b = 23;

	int c = 0;
	

	cout << "a=" << a << endl;

	cout << "b=" << b << endl;

	



	c = a > b ? a : b;

	cout<< "c=" << c << endl;


	(a > b ? a : b) = 520; 

	cout << "b=" << b << endl;

	




	system("pause");

	return 0;
}