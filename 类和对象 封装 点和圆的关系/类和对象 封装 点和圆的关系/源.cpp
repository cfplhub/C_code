
//�жϳ�����������





#include<iostream>
using namespace std;

class Point 
{
public:

	void setX(int x)
	{
		m_X = x;
	}

	int getX()
	{
		return m_X;
	}

	void setY(int y)
	{
		m_Y = y;
	}

	int getY()
	{
		return m_Y;
	}

private:
	int m_X;
	int m_Y;


};

class Circle
{
public:
	void setR(int r)
	{
		m_R = r;
	}

	int getR()
	{
		return m_R;
	}

	void setCenter(Point center)
	{
		m_Center = center;
	}

	Point getCenter()
	{
		return m_Center;
	}

private:
	int m_R;
	Point m_Center;
};

void isInCircle(Circle &c, Point &p)
{	
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	int rdistance = c.getR() * c.getR();

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




int main() {
	//����Բ
	Circle c1;
	c1.setR(10);

	Point center;
	center.setX(0);
	center.setY(0);
	c1.setCenter(center);

	//������
	Point p1;
	p1.setX(3);
	p1.setX(4);


	isInCircle(c1, p1);






	system("pause");
	return 0;
}