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

//初始化机房
void manger::InitComRoom()
{
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vc.push_back(c);
	}
	cout << "当前机房数量为：" << vc.size() << endl;
	ifs.close();
}



void manger::operMenu()
{
	cout << "欢迎管理员:" << this->m_Name << "登录!" << endl;
	cout << "\t\t  ———————------------------—-—\n" ;
	cout << "\t\t |                            |\n";
	cout << "\t\t |         1.添加账号         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         2.查看账号         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         3.查看机房         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         4.清空预约         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |         0.注销登录         |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t  —————————-—------------—--——\n";
	
	cout << "请选择您的操作:" << endl;


}


void manger::addPerson()
{
	cout << "请输入您要添加账号类型" << endl;
	cout << "1、学生" << endl;
	cout << "2、老师" << endl;
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
			cout << "输入有误，请重新输入为数字" << endl;
		}
		else

		{
			break;
		}
	}
	if (select == 1)
	{
		trip = "请输入学号：  ";
		filename = STUDENT_FILE;
		errortrip = "学号重复，请重新输入";
	}
	else
	{
		trip = "请输入职工号：  ";
		filename = TEACHER_FILE;
		errortrip = "职工号重复，请重新输入";
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

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << "  " << pwd<<"  "<<endl;
	this->initVector();
	cout << "添加成功！" << endl;
	ofs.close();
	system("pause");
	system("cls");

}

void PrintStudent(student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void PrintTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}



void manger::showPerson()
{
	int ret = vStu.size();
	int  ret2 = vTea.size();
	if (ret==0&&ret2==0)
	{
		cout << "当前系统数据为零！" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "请选择您要查看的内容：" << endl;
	cout << "1、查看所有学生信息" << endl;
	cout << "2、查看所有老师信息" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void manger::cleanFile()
{
	//cout << "请输入您要清空的文件类型：" << endl;
	//cout << "1、学生" << endl;
	//cout << "2、老师" << endl;
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
	
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
	
}

//void PrintComputer(ComputerRoom&vc)
//{
//	cout << "机房编号：" << vc.m_ComId << " 机房容量：" <<vc.m_MaxNum<< endl;
//}

void manger::showComputer()
{
	cout << "机房信息如下：" << endl;
	//vector<ComputerRoom>vc;
	for (vector<ComputerRoom>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
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
		cout << "文件读取失败" << endl;
		return;
	}
	
	student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size()<<endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}


	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{ 
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
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