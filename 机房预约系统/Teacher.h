#pragma once
#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include<vector>
#include<string>

class Teacher:public Identity
{
public:
	virtual void operMenu();
	Teacher();

	Teacher(int empid, string name, string pwd);

	void showAllOrder();

	void valiOrder();

	int m_EmpId;
};