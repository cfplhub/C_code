#include"circle.h"
#include"point.h"


	//���ð뾶
	void Circle::set_r(int r)
	{
		m_r = r;
	}
	//��ȡ�뾶
	int Circle::get_r()
	{
		return m_r;
	}
	//����Բ��
	void Circle::set_center(Point center)
	{
		m_center = center;
	}
	//��ȡԲ��
	Point Circle::get_center()
	{
		return m_center;
	}
