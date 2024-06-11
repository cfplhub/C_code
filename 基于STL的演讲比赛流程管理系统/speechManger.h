#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<functional>
#include"speaker.h"
#include<fstream>
#include<deque>

class SpeechManager
{
public:
	SpeechManager() ;


	void Show_Menu();
	
	void exitSystem();

	void initSpeaker();

	void startSpeech();

	void speechDraw();

	vector<int>v1;

	vector<int>v2;

	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_dext ;

	void creatspeaker();

	void speechTest();

	void showscore();

	void saveScored();

	void loadScored();

	bool filesIsEmpty;

	map<int, vector<string>>m_Recored;

	void show_Record();

	void clearRecord();

	~SpeechManager();
};

