#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"manger.h"
#include"Teacher.h"
#include<cctype>

void mangerMenu(Identity*& Manger)
{
	while (true)
	{
		Manger->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		//Manger* man = (Manger*)manger;

		manger* man = (manger*)Manger;

		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			man->addPerson();
		}

		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}

		else if (select == 3)//�鿴����
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->cleanFile();
		}
		else
		{
			delete Manger;
			cout << "ע���ɹ�" << endl;
			system("pasue");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& Student)
{
	while (true)
	{
		Student->operMenu();

		student* stu = (student*)Student;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			stu->applyOrder();
		}

		else if (select == 2)
		{
			stu->showMyOrder();
		}

		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}

		else
		{
			delete Student;
			cout << "ע���ɹ���" << endl;

			system("pause");
			system("cls");
			return;
		}
	}
}


void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select;
		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();
		}

		else if (select == 2)
		{
			tea->valiOrder();
		}

		else
		{
			delete teacher;
			cout << "ע���ɹ���" << endl;

			system("pause");
			system("cls");
			return;
		}
	}
}








void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�����������û�����" << endl;
	cin >> name;

	cout << "�������������룺" << endl;
	cin >> pwd;
	

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				
				studentMenu(person);
			
				return;
			}
		}

	}

	else if(type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				TeacherMenu(person);

				return;
			}
		}
	}

	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new manger(name, pwd);

				mangerMenu(person);
				return;
			}
		}
	}
	ifs.close();

	cout << "��֤��¼ʧ�ܣ�" << endl;
	
	system("pause");
	system("cls");
	return;
}






int main()         
{
	while (true)
	{
		cout << "================��ӭʹ�ó���Rap������ϰ��ԤԼϵͳ================" << endl;
		cout << "�������������" << endl;
		cout << "\t\t -------------------------------------------- \n";
		cout << "\t\t|                1.�� ϰ ��                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                2.�� �� ��                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                3.��    ʦ                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                0.��    ��                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t ����������������������������------------------------------ \n";
		cout << "����������ѡ��:" ;
		
		int select = 0;
		cin >> select;
		bool ret = isalpha(select);
		while (1)
		{
			if (ret)
			{
				cout << "������������������Ϊ����" << endl;
			}
			else

			{
				break;
			}
		}
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			
		default:
			cout << "�����������������롣" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	system("pause");
	return 0;
}