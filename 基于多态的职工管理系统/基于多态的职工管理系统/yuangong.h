#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Yuangong :public worker
{
public:
	Yuangong(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();

};