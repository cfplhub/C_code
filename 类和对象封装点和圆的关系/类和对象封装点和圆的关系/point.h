#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	//��������x
	void set_x(int x);
	
	//��ȡ����x
	int get_x();
	
	//��������y
	void set_y(int y);
	
	//��ȡ����y
	int get_y();
	
private:
	int m_x;
	int m_y;
};