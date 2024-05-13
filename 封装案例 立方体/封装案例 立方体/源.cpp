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
	int m_l;//��
	int m_w;//��
	int m_h;//��
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
	
	cout << "���������Ϊ��" << c.calculateV() << endl;
	cout << "���������Ϊ��" << c.calculateS() << endl;
	
	//����ȫ�ֺ����ж�
	bool ret = isSame(c, c1);
	if (ret)
	{
		cout << "c��c1����ȵ�" << endl;
	}
	else {
		cout << "c��c1�ǲ���ȵ�" << endl;
	}

	//���ó�Ա�����ж�
	ret = c.issameByclass(c1);

	if (ret)
	{
		cout << "��Ա�����е�c��c1����ȵ�" << endl;
	}
	else {
		cout << "��Ա�����е�c��c1�ǲ���ȵ�" << endl;
	}



	system("pause");
	return 0;
}