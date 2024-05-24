#include"circle.h"
#include"point.h"


	//设置半径
	void Circle::set_r(int r)
	{
		m_r = r;
	}
	//获取半径
	int Circle::get_r()
	{
		return m_r;
	}
	//设置圆心
	void Circle::set_center(Point center)
	{
		m_center = center;
	}
	//获取圆心
	Point Circle::get_center()
	{
		return m_center;
	}
