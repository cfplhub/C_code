#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Boss.h"
#include"Jingli.h"
#include"yuangong.h"


void test01()
{
	WorkerManager();

	worker* worker = NULL;
	worker = new Jingli(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Yuangong(2, "�°���", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "��������", 2);
	worker->showInfo();
	delete worker;
}



int main()
{

	//test01();
	
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExistSystem();
			break;

		case 1: //���ְ��
			wm.Add_Renshu();
			break;

		case 2: //��ʾְ��
			wm.show_Renshu();
			break;

		case 3: //ɾ��ְ��
		//{
		//	int ret = wm.isexist(5);
		//	if (ret != -1)
		//	{
		//	cout << "ְ������" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ��������" << endl;
		//	}

		//	system("pause");
		//	system("cls");
		//	break;
		//}

			wm.Del_renshu();
			break;

		case 4: //�޸�ְ��
			wm.mod_Zhigong();
			break;

		case 5: //����ְ��
			wm.find_Zhigong();
			break;

		case 6: //����ְ��
			wm.Sort_Zhigong();
			break;

		case 7: //�����ļ�
			wm.clean_FILE();
			break;

		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;


}