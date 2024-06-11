#include<iostream>
#include"speechManger.h"
#include"speaker.h"
#include<ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	//srand(time(nullptr));

	SpeechManager sm;


	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "演讲者编号："<<it->first << " " <<"姓名：" << it->second.m_Name
	//		<< " " <<"分数：" << it->second.m_Score[0] << endl;
	//}
	
	int choice = 0;

	while (true)
	{
		

		sm.Show_Menu();

		cout << "请输入您的的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1 :
			sm.startSpeech();
			break;
		case 2:
			sm.show_Record();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}

	}


	



	system("pause");
	return 0;
}