#pragma once
#include"Identity.h"
#include<iostream>
#include<vector>
#include"ComputerRoom.h"
#include<fstream>
#include<algorithm>
#include"globalFile.h"
#include"orderFile.h"
#include<string>

using namespace std;

class student:public Identity
{
public:
	student();

	student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	vector<ComputerRoom>vCom;

	int m_Id;

};
