#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Jingli :public worker
{
public:
	Jingli(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();

};