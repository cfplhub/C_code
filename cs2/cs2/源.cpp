#include<iostream>
#include<string>
using namespace std;

//一个点类（Point）
class Point
{

public:
	//设置x坐标
	void setX(int x)
	{
		p_x = x;
	}

	//获取x坐标
	int getX()
	{
		return p_x;
	}

	//设置y坐标
	void setY(int y)
	{
		p_y = y;
	}

	//获取y坐标
	int getY()
	{
		return p_y;
	}

private:
	int p_x;
	int p_y;
};

//设计一个圆类Circle
class Circle
{

public:
	//设置半径R
	void setR(int r)
	{
		R = r;
	}

	//获取半径R
	int getR()
	{
		return R;
	}

	//设置圆心
	void setCenter(Point center)
	{
		c_center = center;
	}

	//获取圆心
	Point getCenter()//c_center是Piont类的数据
	{
		return c_center;
	}


private:
	int R;
	//在类中可以让另一个类 作为本类中的成员--与结构体相似
	Point c_center;

};

//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) == c.getR() * c.getR())
		cout << "点在圆上" << endl;
	else if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) > c.getR() * c.getR())
		cout << "点在圆外" << endl;
	else
		cout << "点在圆内" << endl;
}

int main()
{
	//创建并设置点P1
	Point P1;
	P1.setX(10);
	P1.setY(9);

	//创建并设置点P2--圆心
	Point P2;
	P2.setX(10);
	P2.setY(0);

	//设置圆C1
	Circle C1;
	C1.setR(10);
	C1.setCenter(P2);

	isInCircle(C1, P1);

	system("pause");
	return 0;
}