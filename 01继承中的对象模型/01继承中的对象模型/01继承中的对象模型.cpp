#include<iostream>
using namespace std;

class bass
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son :public bass
{
	int m_d;
};

//�������湤�� ������ ������������ʾ
//��ת�̷� C:
//��ת�ļ�;�� cd ����;����
//�鿴����
//cl d1 reportSingleClassLayout���� �ļ���("Դ.cpp")

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}