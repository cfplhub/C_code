#include<iostream>
using namespace std;
//���ص��������
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����++���������ǰ��
	//����������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++()
	{
		++m_Num;
		return *this;
	}
	//����++�������������
	MyInteger operator++(int)//���int��������Ϊռλ��������������ǰ�õ����ͺ��õ���
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
		//���õ���Ҫ����ֵ����Ϊ����������ã������൱�ڷ��ص���һ���ֲ���������á�
		//�ֲ������ڵ�ǰ����ִ�����֮��ͱ��ͷŵ��ˣ���Ҫ�������þ��ǷǷ�������
	}
private:
	int m_Num;
};
//ȫ�ֺ����������������
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
void test()
{
	MyInteger myint;
	cout << ++(++myint);
	cout << myint;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main(void)
{
	//test();
	test02();
	system("pause");
	return 0;
}

