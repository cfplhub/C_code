#include<iostream>
using namespace std;

class point
{
public:

	void set_X(int x)
	{
		this->p_x = x;
	}

	void set_Y(int y)
	{
		this->p_y = y;
	}

	int getX()
	{
		return p_x;
	}

	int getY()
	{
		return p_y;
	}

private:
	int p_x;
	int p_y;
};

class Cirle
{
public:
	void setR(int r)
	{
		this->m_r = r;
	}

	int getR()
	{
		return this->m_r;
	}


	void setcenter(point center)
	{
		this->m_center = center;
	}

	point getcenter()
	{
		return m_center;
	}

private:
	int m_r;
	
	point m_center;
};

void IsInCircle(point& p, Cirle& c)
{
	int distance =
		(c.getcenter().getX() - p.getX()) * (c.getcenter().getX() - p.getX()) +
		(c.getcenter().getY() - p.getY()) * (c.getcenter().getY() - p.getY());

	int rdistance =
		c.getR() * c.getR();
				
	if (distance == rdistance)
	{
		cout << "在圆上" << endl;
	}

	else if (distance > rdistance)
	{
		cout << "在圆外" << endl;
	}

	else
	{
		cout << "在圆内" << endl;
	}

}


int main()
{
	Cirle c1;
	c1.setR(10);

	point center;
	center.set_X(0);
	center.set_Y(0);
	c1.setcenter(center);

	

	point p1;
	p1.set_X(10);
	p1.set_Y(0);

	IsInCircle(p1, c1);
	system("pause");
	return 0;
}