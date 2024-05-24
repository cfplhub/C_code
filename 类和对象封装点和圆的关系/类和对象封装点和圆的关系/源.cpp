#include <iostream>
using namespace std;
#include"circle.h"
#include"point.h"


//点类
//class Point
//{
//public:
//	//设置坐标x
//	void set_x(int x)
//	{
//		m_x = x;
//	}
//	//获取坐标x
//	int get_x()
//	{
//		return m_x;
//	}
//	//设置坐标y
//	void set_y(int y)
//	{
//		m_y = y;
//	}
//	//获取坐标y
//	int get_y()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//圆类
//class Circle
//{
//public:
//	//设置半径
//	void set_r(int r)
//	{
//		m_r = r;
//	}
//	//获取半径
//	int get_r()
//	{
//		return m_r;
//	}
//	//设置圆心
//	void set_center(Point center)
//	{
//		m_center = center;
//	}
//	//获取圆心
//	Point get_center()
//	{
//		return m_center;
//	}
//private:
//	int m_r;
//	Point m_center;
//};
void isIncircle(Circle& c, Point& p)
{
	//计算两点之间距离的平方
	int distance =
		(c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
		(c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
	//计算半径的平方
	int rdistance = c.get_r() * c.get_r();

	if (distance == rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//创建圆
	Circle c1;
	c1.set_r(10);
	Point center;
	center.set_x(10);
	center.set_y(10);
	c1.set_center(center);

	//创建点
	Point p1;
	p1.set_x(3);
	p1.set_y(4);

	//判断关系
	isIncircle(c1, p1);

	system("pause");
	return 0;
}
