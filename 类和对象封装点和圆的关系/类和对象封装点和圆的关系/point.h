#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	//设置坐标x
	void set_x(int x);
	
	//获取坐标x
	int get_x();
	
	//设置坐标y
	void set_y(int y);
	
	//获取坐标y
	int get_y();
	
private:
	int m_x;
	int m_y;
};