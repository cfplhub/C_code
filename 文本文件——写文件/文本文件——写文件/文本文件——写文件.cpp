#include<iostream>
using namespace std;
#include<fstream>

void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "ÐÕÃû£º³Â½ÜöÎÎÚ??" << endl;
	ofs << "ÄêÁä£º26" << endl;
	ofs << "ÊôÐÔ£ºÖí" << endl;
	ofs << "·ôÉ«£ºÎÚ" << endl;
	ofs.close();



}



int main()  
{

	test01();



	system("pause");
	return 0;
}