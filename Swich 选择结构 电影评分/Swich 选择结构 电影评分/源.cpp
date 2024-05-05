#include <iostream>
using namespace std;

int main() {

	cout << "请给电影 满江红 评分(0~10)" << endl;

	int score = 0;

	cin >> score;

	
	cout << " 您给的分数为: " << score << endl;

	switch (score) {

		case 10:
		cout << "您认为这电影简直无敌 " << endl;
		break;

		case 9:
		cout << "您认为这电影简直无敌 " << endl;
		break;


		case 8:
		cout << "您认为这电影还不错" << endl;
		break;


		case 7:
		cout << "您认为这电影还不错 " << endl;
		break;


		case 6:
		cout << "您认为这电影还一般 " << endl;
		break;


		case 5:
		cout << "您认为这电影还一般 " << endl;
		break;



		default:
		cout << "您认为这电影是一部烂片 " << endl;
		break;

	}
	if (score > 10)
		cout << "基于您给的分数不符合评分标准，以上结果自动作废" << endl;


	/* 
	if和swich有什么区别
	swich缺点：判断时只能是整型 ，或者字符型，不能是一个区间；
	swich优点：结构清晰，执行效率高
	
	
	*/


	system("pause");
	return 0;
}