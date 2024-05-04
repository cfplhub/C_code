#include<iostream>
#include<string>
using namespace std;

//创建立方体类
class Cube
{
private:
	//属性 一般设置为私有 长宽高
	int m_L;
	int m_W;
	int m_H;
public:
	//设置长
	void setL(int L)
	{
		m_L = L;
	}

	//获取长
	int getL()
	{
		return m_L;
	}

	//设置宽
	void setW(int W)
	{
		m_W = W;
	}

	//获取宽
	int getW()
	{
		return m_W;
	}

	//设置高
	void setH(int H)
	{
		m_H = H;
	}
	//获取高
	int getH()
	{
		return m_H;
	}

	//行为 1、获取立方体面积
	int getS()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	//行为 2、获取立方体体积	
	int getV()
	{
		return m_L * m_W * m_H;
	}
	//利用成员函数判断两个立方体是否相等
	bool isSame01(Cube& b)//只需要传另一个立方体进来与类内的立方体进行比较
	{
		if (m_L == b.getL() && m_W == b.getW() && m_H == b.getH())
			return true;
		else
			return false;
	}

};

//全局函数
bool isSame02(Cube a, Cube b)
{
	if (a.getL() == b.getL() && a.getW() == b.getW() && a.getH() == b.getH())
		return true;
	return false;
}

int main()
{
	//创建一个立方体对象
	int l;
	int w;
	int h;
	cout << "请输入立方体a1的长： ";
	cin >> l;

	cout << "请输入立方体a1的宽： ";
	cin >> w;

	cout << "请输入立方体a1的高： ";
	cin >> h;

	Cube a1;
	a1.setL(l);
	a1.setW(w);
	a1.setH(h);

	cout << "经计算得出：  "<<endl;
	cout << "立方体a1的面积为：" << a1.getS() << endl;
	cout << "立方体a1的体积为：" << a1.getV() << endl;

	cout << "请输入立方体a2的长： ";
	cin >> l;

	cout << "请输入立方体a2的宽： ";
	cin >> w;

	cout << "请输入立方体a2的高： ";
	cin >> h;

	Cube a2;
	a2.setL(l);
	a2.setW(w);
	a2.setH(h);

	cout << "经计算得出：  "<<endl;
	cout << "立方体a2的面积为：" << a2.getS() << endl;
	cout << "立方体a2的体积为：" << a2.getV() << endl;

	//利用成员函数判断两个立方体是否相等
	bool flag = a2.isSame01(a1);
	if (flag)
		cout << "成员函数判断:立方体a1与立方体a2相等" << endl;
	else
		cout << "成员函数判断:立方体a1与立方体a2不相等" << endl;

	//利用全局函数判断两个立方体是否相等
	bool ret = isSame02(a1, a2);
	if (ret)
		cout << "全局函数判断:立方体a1与立方体a2相等" << endl;
	else
		cout << "全局函数判断:立方体a1与立方体a2不相等" << endl;

	system("pause");
	return 0;
}