#include<iostream>
using namespace std;
const double PI = 3.14;
class Circle {
public:

	int m_r;
	double calculate() {

		return 2 * PI * m_r;
	}
};


int main() {


	Circle c1;
	c1. m_r = 10;
	cout << "Ô²µÄÖÜ³¤:" << c1.calculate() << endl;


	system("pause");
	return 0;
}
