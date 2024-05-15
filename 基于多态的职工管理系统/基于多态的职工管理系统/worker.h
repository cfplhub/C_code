#pragma once
#include<iostream>
using namespace std;
#include<string>

class worker
{
public:
	virtual void showInfo() = 0;

	virtual string getDepName() = 0;

	int m_Id;
	string m_Name;
	int m_DepId;
};