#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class Circle
{
public:
	//设置半径
	void set_r(int r);
	
	//获取半径
	int get_r();
	
	//设置圆心
	void set_center(Point center);
	
	//获取圆心
	Point get_center();
	
private:
	int m_r;
	Point m_center;
};