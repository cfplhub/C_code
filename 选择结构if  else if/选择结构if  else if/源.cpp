#include  <iostream>
using namespace std;

int main() {

	cout << "����ĸ߿��Ѿ������ˣ���ӭ��������ѧ���߿�������ѯϵͳ" << endl;

	int score = 0;

	cout << "���������ķ���:" << score << endl;

	cin >> score;

	cout << "������ķ���Ϊ��" << score << endl;

	if (score > 600)
	{

		cout << "��ϲ������һ����ѧ" << endl;

		if (score > 800)

			cout << "������ţ��������������������й���������Ψһһ��IQ�ﵽ999+�����" << endl;

		if (score > 700)
		{
			cout << "�������廪��ѧ" << endl;
		}
		else if (score > 670)
		{
			cout << "�����ϱ�����ѧ" << endl;
		}

		else if (score > 630)
		{
			cout << "�������й������ѧ" << endl;
		}

		else
			cout << "�����ϱ��������ѧ" << endl;
	}
	else if (score > 500)

	{
		cout << "��ϲ�����϶�����ѧ" << endl;

		if (score > 550)
		{
			cout << "���������ڴ�ѧ" << endl;

		}
		else
		{
			cout << "�����Ϲ㶫�����ѧ" << endl;

		}


	}

	else if (score > 400)
	{
		cout << "��ϲ������������´�ѧ" << endl;
	}


	else

	{
		cout << "��ϲ����������ѧ" << endl;
	}





	system("pause");

	return 0;
}
