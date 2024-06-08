#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<string>
#include<algorithm>
#include<map>

class orderFile
{
public:
	orderFile();

	void updateOrder();

	int m_Size;

	map<int, map<string, string>>orderDate;

};