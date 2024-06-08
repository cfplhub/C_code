#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
#include<algorithm>

class manger :public Identity
{
public:

	virtual void operMenu();

	manger();

	manger(string name, string pwd);

	void addPerson();

	void showPerson();

	void cleanFile();

	void showComputer();

	void initVector();

	vector<student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vc;

	bool checkRepeat(int id, int type);

	void InitComRoom();
	
};

