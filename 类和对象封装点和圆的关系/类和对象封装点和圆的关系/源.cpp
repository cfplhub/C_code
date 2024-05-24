#include <iostream>
using namespace std;
#include"circle.h"
#include"point.h"


//����
//class Point
//{
//public:
//	//��������x
//	void set_x(int x)
//	{
//		m_x = x;
//	}
//	//��ȡ����x
//	int get_x()
//	{
//		return m_x;
//	}
//	//��������y
//	void set_y(int y)
//	{
//		m_y = y;
//	}
//	//��ȡ����y
//	int get_y()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//Բ��
//class Circle
//{
//public:
//	//���ð뾶
//	void set_r(int r)
//	{
//		m_r = r;
//	}
//	//��ȡ�뾶
//	int get_r()
//	{
//		return m_r;
//	}
//	//����Բ��
//	void set_center(Point center)
//	{
//		m_center = center;
//	}
//	//��ȡԲ��
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
	//��������֮������ƽ��
	int distance =
		(c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
		(c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
	//����뾶��ƽ��
	int rdistance = c.get_r() * c.get_r();

	if (distance == rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	//����Բ
	Circle c1;
	c1.set_r(10);
	Point center;
	center.set_x(10);
	center.set_y(10);
	c1.set_center(center);

	//������
	Point p1;
	p1.set_x(3);
	p1.set_y(4);

	//�жϹ�ϵ
	isIncircle(c1, p1);

	system("pause");
	return 0;
}
