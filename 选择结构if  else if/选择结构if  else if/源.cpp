#include  <iostream>
using namespace std;

int main() {

	cout << "今年的高考已经结束了，欢迎考生进入学生高考分数查询系统" << endl;

	int score = 0;

	cout << "请输入您的分数:" << score << endl;

	cin >> score;

	cout << "您输入的分数为：" << score << endl;

	if (score > 600)
	{

		cout << "恭喜您考上一本大学" << endl;

		if (score > 800)

			cout << "旷世奇才，百年难遇，您将是新中国建国以来唯一一个IQ达到999+的天才" << endl;

		if (score > 700)
		{
			cout << "您考上清华大学" << endl;
		}
		else if (score > 670)
		{
			cout << "您考上北京大学" << endl;
		}

		else if (score > 630)
		{
			cout << "您考上中国人民大学" << endl;
		}

		else
			cout << "您考上北京航天大学" << endl;
	}
	else if (score > 500)

	{
		cout << "恭喜您考上二本大学" << endl;

		if (score > 550)
		{
			cout << "您考上深圳大学" << endl;

		}
		else
		{
			cout << "您考上广东海洋大学" << endl;

		}


	}

	else if (score > 400)
	{
		cout << "恭喜您考上普宁民德大学" << endl;
	}


	else

	{
		cout << "恭喜您进入社会大学" << endl;
	}





	system("pause");

	return 0;
}
