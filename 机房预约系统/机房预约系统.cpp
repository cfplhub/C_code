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

		//将父类指针转为子类指针，调用子类里其他接口
		//Manger* man = (Manger*)manger;

		manger* man = (manger*)Manger;

		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			man->addPerson();
		}

		else if (select == 2)//查看账号
		{
			man->showPerson();
		}

		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->cleanFile();
		}
		else
		{
			delete Manger;
			cout << "注销成功" << endl;
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
			cout << "注销成功！" << endl;

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
			cout << "注销成功！" << endl;

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
		cout << "文件不存在！" << endl;
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
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入您的用户名：" << endl;
	cin >> name;

	cout << "请输入您的密码：" << endl;
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
				cout << "学生验证登陆成功！" << endl;
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
				cout << "老师验证登陆成功！" << endl;
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
				cout << "管理员验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new manger(name, pwd);

				mangerMenu(person);
				return;
			}
		}
	}
	ifs.close();

	cout << "验证登录失败！" << endl;
	
	system("pause");
	system("cls");
	return;
}






int main()         
{
	while (true)
	{
		cout << "================欢迎使用唱跳Rap篮球练习室预约系统================" << endl;
		cout << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------------------- \n";
		cout << "\t\t|                1.练 习 生                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                2.制 作 人                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                3.导    师                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t|                0.退    出                  |\n";
		cout << "\t\t|                                            |\n";
		cout << "\t\t ——————————————------------------------------ \n";
		cout << "请输入您的选择:" ;
		
		int select = 0;
		cin >> select;
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			
		default:
			cout << "输入有误，请重新输入。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	system("pause");
	return 0;
}