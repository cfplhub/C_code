#include"speechManger.h"


SpeechManager::SpeechManager()
{
	this->initSpeaker();

	this->creatspeaker();

	this->loadScored();
}

void SpeechManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "***********欢迎参加演讲比赛*******" << endl;
	cout << "************1.开始比赛************" << endl;
	cout << "************2.查看记录************" << endl;
	cout << "************3.清空记录************" << endl;
	cout << "************0.退出程序************" << endl;
	cout << "**********************************" << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}


void SpeechManager::initSpeaker()
{
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_dext = 1;

	this->m_Recored.clear();
}


void SpeechManager::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "个人练习生";
		name += nameseed[i];
		Speaker sp;
		sp.m_Name = name;

		for (int j= 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		
		v1.push_back(i + 1001);
		
		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}


}


void SpeechManager::startSpeech()
{
	this->speechDraw();

	this->speechTest();

	this->showscore();

	this->m_dext++;

	this->speechDraw();

	this->speechTest();

	this->showscore();

	this->saveScored();

	this->initSpeaker();

	this->creatspeaker();

	this->loadScored();

	cout << "本届比赛完毕!"<<endl;

		system("pause");
		system("cls");

}


void SpeechManager::speechDraw()
{
	cout << "第<<" << m_dext << ">>轮比赛正在抽签" << endl;
	cout << "-----------------------" << endl;
	cout << "抽签结果如下：" << endl;

	if (m_dext == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	else
	{
		random_shuffle(v2.begin(), v2.end());
		
		cout << "--------第<<" << this->m_dext << ">>轮抽签结果如下：--------" << endl;
		cout << "-----------------------" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	system("pause");
	cout << endl;

}

void SpeechManager::speechTest()
{

	cout << "------------第" << this->m_dext << "轮比赛正式开始------------" << endl;

	vector<int>v_Scr;
	multimap<double, int,greater<double>>groupscore;
	int num = 0;

	if (m_dext == 1)
	{
		v_Scr = v1;
	}

	else
	{
		v_Scr = v2;
	}

	for (vector<int>::iterator it = v_Scr.begin(); it != v_Scr.end(); it++)
	{
		num++;
		deque<double>d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;

			//cout << score << "\t";

			d.push_back(score);

		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//cout << "编号：" << *it << "  " << "姓名：" << this->m_Speaker[*it].m_Name << "  平均分：" << avg << endl;


		this->m_Speaker[*it].m_Score[this->m_dext - 1] = avg;

		groupscore.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int,greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名:" << this->m_Speaker[it->second].m_Name <<
					" 分数：" << this->m_Speaker[it->second].m_Score[this->m_dext-1] << endl;
			}
			

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; count++, it++)
			{
				if (this->m_dext == 1)
				{
					v2.push_back((*it).second);
				}

				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupscore.clear();
			
			
		}
		
	}
	cout << "-----------第" << this->m_dext << "轮比赛正式结束！-------------" << endl;
	system("pause");


}

void SpeechManager::showscore()
{
	cout << "---------第" << this->m_dext << "轮晋级选手信息如下：---------" << endl;

	vector<int>v;
	if (this->m_dext == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}


	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 分数：" << this->m_Speaker[*it].m_Score[this->m_dext - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	this->Show_Menu();
	cout << endl;

}

void SpeechManager::saveScored()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "文件已保存！" << endl;
	this->filesIsEmpty = false;
}


void SpeechManager::loadScored()
{
	ifstream ifs("speech.csv",ios::in);

	if(!ifs.is_open())
	{
		this->filesIsEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return ;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->filesIsEmpty = true;
		ifs.close();
		return;
	}

	this->filesIsEmpty = false;
	ifs.putback(ch);
	int index = 0;

	string data;
	while (ifs >> data)
	{
		//cout << data << endl;

		int pos = -1;
		int start = 0;
		vector<string>v;
		
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << " ";
			v.push_back(temp);
			start = pos + 1;

		}
		
		this->m_Recored.insert(make_pair(index, v));
		index++;
	}

	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_Recored.begin(); it != m_Recored.end(); it++)
	//{
	//	cout << "第"<<it->first+1<<"届" << " \t冠军编号：" << it->second[0] << "\t得分：" << it->second[1] << endl;
	//}

	//system("pause");
	//system("cls");

}

void SpeechManager::show_Record()
{
	//for (map<int, vector<string>>::iterator it = m_Recored.begin(); it != m_Recored.end(); it++)
	//{
	//	cout << "第" << it->first + 1 << "届" <<
	//		"   冠军编号：" << it->second[0] << "  得分：" << it->second[1] << "  季军编号：" << it->second[3]
	//		<< "  得分：" << it->second[4] << "  亚军编号：" << it->second[5] << "  得分：" << it->second[6] << endl;
	//}

	if (this->filesIsEmpty)
	{
		cout << "文件为空或者文件不存在" << endl;
	}

	for (int i = 0; i < this->m_Recored.size(); i++)
	{
		
		cout << "第" << i + 1 << "届"
			<< "  冠军编号为：" << this->m_Recored[i][0] << "  得分：" << this->m_Recored[i][1]
			<< "  亚军编号为：" << this->m_Recored[i][2] << "  得分：" << this->m_Recored[i][3]
			<< "  季军编号为：" << this->m_Recored[i][4] << "  得分：" << this->m_Recored[i][5] << endl;
	}


	system("pause");
	system("cls");
}


void SpeechManager::clearRecord()
{
	cout << "请确定是否删除记录！" << endl;
	cout << "1、确定  2、取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeaker();
		this->creatspeaker();
		this->loadScored();
		
		
		cout << "清空成功！" << endl;
	}


	system("pause");
	system("cls");


}

SpeechManager::~SpeechManager()
{

}