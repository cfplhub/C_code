#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class Circle
{
public:
	//���ð뾶
	void set_r(int r);
	
	//��ȡ�뾶
	int get_r();
	
	//����Բ��
	void set_center(Point center);
	
	//��ȡԲ��
	Point get_center();
	
private:
	int m_r;
	Point m_center;
};