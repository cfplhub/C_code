#include <iostream>
using namespace std;

int main() {

	cout << "�����Ӱ ������ ����(0~10)" << endl;

	int score = 0;

	cin >> score;

	
	cout << " �����ķ���Ϊ: " << score << endl;

	switch (score) {

		case 10:
		cout << "����Ϊ���Ӱ��ֱ�޵� " << endl;
		break;

		case 9:
		cout << "����Ϊ���Ӱ��ֱ�޵� " << endl;
		break;


		case 8:
		cout << "����Ϊ���Ӱ������" << endl;
		break;


		case 7:
		cout << "����Ϊ���Ӱ������ " << endl;
		break;


		case 6:
		cout << "����Ϊ���Ӱ��һ�� " << endl;
		break;


		case 5:
		cout << "����Ϊ���Ӱ��һ�� " << endl;
		break;



		default:
		cout << "����Ϊ���Ӱ��һ����Ƭ " << endl;
		break;

	}
	if (score > 10)
		cout << "���������ķ������������ֱ�׼�����Ͻ���Զ�����" << endl;


	/* 
	if��swich��ʲô����
	swichȱ�㣺�ж�ʱֻ�������� �������ַ��ͣ�������һ�����䣻
	swich�ŵ㣺�ṹ������ִ��Ч�ʸ�
	
	
	*/


	system("pause");
	return 0;
}