#include<iostream>
using namespace std;
#include<string>

class cube
{
public:
	void setl(int l)
	{
		m_l = l;
	}

	int getl()
	{
		return m_l;
	}

	void setw(int w)
	{
		m_w = w;
	}

	int getw()
	{
		return m_w;
	}

	void seth(int h)
	{
		m_h = h;
	}

	int geth()
	{
		return m_h;
	}

	int calculateS()
	{
		return 2 * m_l * m_w + 2 * m_l * m_h + 2 * m_w * m_h;
	}

	int calculateV()
	{
		return m_l * m_w * m_h;
	}

	bool issameByclass(cube &c)
	{
		if (m_l == c.getl() && m_w == c.getw() && m_h == c.geth())
		{
			return true;
		}
		return false;
	}

private:
	int m_l;//长
	int m_w;//宽
	int m_h;//高
};

bool isSame(cube &c, cube &c1)
{
	if (c.getl() == c1.getl()&&c.getw() ==c1.getw()&&c.geth()==c1.geth())
	{
		return true;
	}

	return false;
}

int main() {

	cube c;
	c.setl(10);
	c.seth(10);
	c.setw(10);

	cube c1;
	c1.setl(10);
	c1.seth(10);
	c1.setw(10);
	
	cout << "立方体体积为：" << c.calculateV() << endl;
	cout << "立方体面积为：" << c.calculateS() << endl;
	
	//利用全局函数判断
	bool ret = isSame(c, c1);
	if (ret)
	{
		cout << "c和c1是相等的" << endl;
	}
	else {
		cout << "c和c1是不相等的" << endl;
	}

	//利用成员函数判断
	ret = c.issameByclass(c1);

	if (ret)
	{
		cout << "成员函数中的c和c1是相等的" << endl;
	}
	else {
		cout << "成员函数中的c和c1是不相等的" << endl;
	}



	system("pause");
	return 0;
}