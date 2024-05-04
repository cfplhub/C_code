#include<iostream>
#include<string>
using namespace std;

//һ�����ࣨPoint��
class Point
{

public:
	//����x����
	void setX(int x)
	{
		p_x = x;
	}

	//��ȡx����
	int getX()
	{
		return p_x;
	}

	//����y����
	void setY(int y)
	{
		p_y = y;
	}

	//��ȡy����
	int getY()
	{
		return p_y;
	}

private:
	int p_x;
	int p_y;
};

//���һ��Բ��Circle
class Circle
{

public:
	//���ð뾶R
	void setR(int r)
	{
		R = r;
	}

	//��ȡ�뾶R
	int getR()
	{
		return R;
	}

	//����Բ��
	void setCenter(Point center)
	{
		c_center = center;
	}

	//��ȡԲ��
	Point getCenter()//c_center��Piont�������
	{
		return c_center;
	}


private:
	int R;
	//�����п�������һ���� ��Ϊ�����еĳ�Ա--��ṹ������
	Point c_center;

};

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) == c.getR() * c.getR())
		cout << "����Բ��" << endl;
	else if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) > c.getR() * c.getR())
		cout << "����Բ��" << endl;
	else
		cout << "����Բ��" << endl;
}

int main()
{
	//���������õ�P1
	Point P1;
	P1.setX(10);
	P1.setY(9);

	//���������õ�P2--Բ��
	Point P2;
	P2.setX(10);
	P2.setY(0);

	//����ԲC1
	Circle C1;
	C1.setR(10);
	C1.setCenter(P2);

	isInCircle(C1, P1);

	system("pause");
	return 0;
}