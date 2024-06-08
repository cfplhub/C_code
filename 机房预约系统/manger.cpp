#include"manger.h"
#include<cctype>
#include<algorithm>
#include<functional>
#include"globalFile.h"



manger::manger()
{

}

manger::manger(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	this->InitComRoom();

}

//��ʼ������
void manger::InitComRoom()
{
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vc.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vc.size() << endl;
	ifs.close();
}



void manger::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��¼!" << endl;
	cout << "\t\t  ��������������------------------��-��\n" ;
	cout << "\t\t |                            |\n";
	cout << "\t\t |         1.����˺�         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         2.�鿴�˺�         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         3.�鿴����         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         4.���ԤԼ         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         0.ע����¼         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t  ������������������-��------------��--����\n";
	
	cout << "��ѡ�����Ĳ���:" << endl;


}


void manger::addPerson()
{
	cout << "��������Ҫ����˺�����" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;
	int select = 0;
	cin >> select;
	string trip;
	string errortrip;
	string filename;
	ofstream ofs;

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
	if (select == 1)
	{
		trip = "������ѧ�ţ�  ";
		filename = STUDENT_FILE;
		errortrip = "ѧ���ظ�������������";
	}
	else
	{
		trip = "������ְ���ţ�  ";
		filename = TEACHER_FILE;
		errortrip = "ְ�����ظ�������������";
	}
	
	ofs.open(filename, ios::out | ios::app);
	int id;
	string  name;
	string pwd;

	cout << trip << endl;
	//cin >> id;
	while (1)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errortrip << endl;
			
		}
		else
		{
			break;
		}

	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << "  " << pwd<<"  "<<endl;
	this->initVector();
	cout << "��ӳɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");

}

void PrintStudent(student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void PrintTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}



void manger::showPerson()
{
	int ret = vStu.size();
	int  ret2 = vTea.size();
	if (ret==0&&ret2==0)
	{
		cout << "��ǰϵͳ����Ϊ�㣡" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "��ѡ����Ҫ�鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ����Ϣ" << endl;
	cout << "2���鿴������ʦ��Ϣ" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void manger::cleanFile()
{
	//cout << "��������Ҫ��յ��ļ����ͣ�" << endl;
	//cout << "1��ѧ��" << endl;
	//cout << "2����ʦ" << endl;
	//string filename;
	//int select;
	//cin >> select;

	//while (1)
	//{
	//	
	//	if (select == 1)
	//	{
	//		filename = STUDENT_FILE;

	//	}
	//	else
	//	{
	//		filename = TEACHER_FILE;
	//	}

	//	ofstream ofs;
	//	ofs.open(filename, ios::trunc);
	//	break;
	//}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
	
}

//void PrintComputer(ComputerRoom&vc)
//{
//	cout << "������ţ�" << vc.m_ComId << " ����������" <<vc.m_MaxNum<< endl;
//}

void manger::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	//vector<ComputerRoom>vc;
	for (vector<ComputerRoom>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "  �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
	
}

void manger::initVector()
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	
	student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size()<<endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}


	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{ 
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}


bool manger::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}