#include"WorkerManager.h";

#include<iostream>
using namespace std;


WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	 
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		this->m_Renshu = 0;

		this->m_Renshuarray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;

	}


		char ch;
		ifs >> ch;
		if (ifs.eof())//eof文件尾部
		{
			//文件为空
	      //cout<<"文件为空"<<endl;
			//初始化属性
			//初始化记录人数
			this->m_Renshu = 0;
			//初始化数组指针
			this->m_Renshuarray = NULL;
			//初始化文件是否为空
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
			
		}


		//3.文件存在，并有数据
		int num = this->get_Renshu();
		//cout << "职工人数为：" << num << endl;
		this->m_Renshu = num;

		//开辟空间
		this->m_Renshuarray = new worker * [this->m_Renshu];

		//将文件中的数据，存在数组中
		this->init_Renshu();

		//for (int i=0;i<m_Renshu;i++)
		//{
		//  cout << "职工编号：" << this->m_Renshuarray[i]->m_Id
		//      << "职工姓名：" << this->m_Renshuarray[i]->m_Name
		//      << "职工编号：" << this->m_Renshuarray[i]->m_DepId << endl;
		//}

}


void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "*****欢迎使用职工管理系统*****" << endl;
	cout << "*******0-退出管理程序*********" << endl;
	cout << "*******1-增加职工信息*********" << endl;
	cout << "*******2-显示职工信息*********" << endl;
	cout << "*******3-删除离职职工*********" << endl;
	cout << "*******4-修改职工信息*********" << endl;
	cout << "*******5-查找职工信息*********" << endl;
	cout << "*******6-按照编号排序*********" << endl;
	cout << "*******7-清空所有文档*********" << endl;
	cout << "******************************" << endl;
	
}

void WorkerManager::ExistSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}

//添加职工
void WorkerManager::Add_Renshu()
{
	cout << "请输入添加职工数量：" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		//计算新空间大小
		int newSize = this->m_Renshu + addnum;

		//开辟新空间
		worker** newspace = new worker * [newSize];



		//将原来空间下数据，拷贝到新空间
		if (this->m_Renshuarray != NULL)
		{
			for (int i = 0; i < this->m_Renshu; i++)
			{
				newspace[i] = this->m_Renshuarray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addnum; i++)
		{
			int id = 0;
			string name;
			int dSelect;


			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Yuangong(id, name, 1);
				break;

			case 2:
				worker = new Jingli(id, name, 2);
				break;

			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}

			newspace[this->m_Renshu + i] = worker;

		}

		//释放原有空间
		delete[] this->m_Renshuarray;

		this->m_Renshuarray = newspace;

		this->m_Renshu = newSize;

		//文件不为空
		this->m_FileIsEmpty = false;

		cout << "成功添加" << addnum << "名新职工" << endl;

		this->save();
	}
		else
		{
			cout << "输入数据有误" << endl;
		}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_Renshu; i++)
	{
		ofs << this->m_Renshuarray[i]->m_Id << "  "
			<< this->m_Renshuarray[i]->m_Name << "  "
			<< this->m_Renshuarray[i]->m_DepId << endl;
	}

	ofs.close();
}

int  WorkerManager::get_Renshu()
{
	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;

	}

	ifs.close();

	return num;
}

void WorkerManager::init_Renshu()
{
	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Yuangong(id, name, dId);
		}

		else if (dId == 2)
		{
			worker = new Jingli(id, name, dId);
		}

		else 
		{
			worker = new Boss(id, name, dId);
		}

		this->m_Renshuarray[index] = worker;
		index++;
	}

	ifs.close();
}


//显示职工
void WorkerManager::show_Renshu()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
	}

	else
	{
		for (int i = 0; i < this->m_Renshu; i++)
		{
			this->m_Renshuarray[i]->showInfo();
		}

	}

	system("pause");
	system("cls");
}

//判断职工是否存在
int  WorkerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_Renshu; i++)
	{
		if (this->m_Renshuarray[i]->m_Id == id)
		{
			index = i;

			break;
		}

	}

	return index;
}





//删除职工
void WorkerManager::Del_renshu()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}

	else
	{
		cout << "请输入您要删除的职工编号" << endl;

		int id = 0;

		cin >> id;

		int index = this->isExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_Renshu - 1; i++)
			{
				this->m_Renshuarray[i] = this->m_Renshuarray[i + 1];
			}

			//更新数组中记录人员个数
			this->m_Renshu--;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;

		}
		
		else
		{
			cout << "删除失败，未找到职工" << endl;
		}
	
		
	}
	system("pause");
	system("cls");
}


//按照姓名判断是否存在
//int WorkerManager::isExist2(string name)
//{
//	int index = -1;
//
//	for (int i = 0; i < this->m_Renshu; i++)
//	{
//		if (this->m_Renshuarray[i]->m_Name == name)
//		{
//			index = i;
//
//			break;
//		}
//
//	}
//
//	return index;
//}


//void WorkerManager::Del_renshu()
//{
//	if (this->m_FileIsEmpty)
//	{
//		cout << "文件不存在或者记录为空" << endl;
//	}
//
//	else
//	{
//		cout << "请输入您要删除职工的方式：" << endl;
//		cout << "1、按照职工编号删除" << endl;
//		cout << "2、按照职工姓名删除" << endl;
//
//		int select = 0;
//		cin >> select;
//
//		if (select == 1)
//		{
//			cout << "请输入您要删除的职工编号" << endl;
//			int id = 0;
//
//			cin >> id;
//
//			int index = this->isExist(id);
//
//			if (index != -1)
//			{
//				for (int i = index; i < this->m_Renshu - 1; i++)
//				{
//					this->m_Renshuarray[i] = this->m_Renshuarray[i + 1];
//				}
//
//				//更新数组中记录人员个数
//				this->m_Renshu--;
//				//数据同步更新到文件中
//				this->save();
//				cout << "删除成功" << endl;
//
//			}
//
//			else
//			{
//				cout << "删除失败，未找到职工" << endl;
//			}
//
//
//		}
//
//		else if (select == 2)
//		{
//			cout << "请输入您要删除的职工姓名" << endl;
//			string name;
//			
//			cin >> name;
//			
//
//			bool flag = false;
//			int index = this->isExist2(name);
//
//			if (index != -1)
//			{
//				for (int i = index; i < this->m_Renshu - 1; i++)
//				{
//					if (this->m_Renshuarray[i]->m_Name == name)
//					{
//						this->m_Renshuarray[i] = this->m_Renshuarray[i + 1];
//
//					}
//
//					//更新数组中记录人员个数
//					this->m_Renshu--;
//
//					//数据同步更新到文件中
//					this->save();
//
//					cout << "删除成功" << endl;
//					flag = true;
//				}
//			}
//
//			if (flag == false)
//			{
//				cout << "查无此人，删除失败" << endl;
//			}
//		}
//
//		system("pause");
//		system("cls");
//		
//	}
//	
//}


//修改职工
void WorkerManager::mod_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}

	else
	{
		cout << "请输入您要修改职工的编号" << endl;

		int id;
		cin >> id;

		int ret = this->isExist(id);

		if (ret != -1)
		{
			delete this->m_Renshuarray[ret];

			int newid;
			string newname = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名：" << endl;
			cin >> newname;

			cout << "请输入新职工部门编号：" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Yuangong(newid, newname, dSelect);
				break;

			case 2:
				worker = new Jingli(newid, newname, dSelect);
				break;

			case 3:
				worker = new Boss(newid, newname, dSelect);
				break;

			default:
				break;
			}

			this->m_Renshuarray[ret] = worker;
			this->save();
			cout << "修改成功" << endl;
	
		}

		else
		{
			cout << "查无此人，请重新输入" << endl;

		}

	}
	system("pause");
	system("cls");

}

//查找职工
void WorkerManager::find_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}

	else
	{
		cout << "请输入您要查找职工方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入您要查找的职工编号" << endl;
			int id;
			cin >> id;

			int ret = this->isExist(id);

			if (ret != -1)
			{
				cout << "为您找到" << id << "号职工，该职工信息如下：" << endl;

				this->m_Renshuarray[ret]->showInfo();
			}

			else
			{
				cout << "查无此人！" << endl;
			}
		}

		else if (select == 2)
		{
			cout << "请输入您要查找职工的姓名：" << endl;
			string name;
			cin >> name;
			
			bool flag = false;

			for(int i=0;i<this->m_Renshu;i++)
			{ 
				if (this->m_Renshuarray[i]->m_Name == name)
				{
					cout << "查找成功，为您找到" 
						 << this->m_Renshuarray[i]->m_Id 
						 << "号职工的信息如下：" << endl;

					flag = true;

					this->m_Renshuarray[i]->showInfo();
				}


			}
			
			if (flag == false )
			{
				cout << "查无此人，查找失败" << endl;
			}
		}
	}

	
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

		system("pause");
		system("cls");
	}

	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按照职工号进行升序" << endl;
		cout << "2、按照职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_Renshu; i++)
		{
			int MinorMax = i;

			for (int j = i + 1; j < this->m_Renshu; j++)
			{
				if (select == 1)
				{
					if (this->m_Renshuarray[MinorMax]->m_Id > this->m_Renshuarray[j]->m_Id)
					{
						MinorMax = j;
					}
				}

				else if (select == 2)
				{
					if (this->m_Renshuarray[MinorMax]->m_Id < this->m_Renshuarray[j]->m_Id)
					{
						MinorMax = j;
					}
				}

				else
				{
					cout << "输入有误，请重新输入！" << endl;

					system("pause");
					system("cls");
					return ;
				}
			}

			if (i != MinorMax)
			{
				worker* temp = m_Renshuarray[i];
				m_Renshuarray[i] = m_Renshuarray[MinorMax];
				m_Renshuarray[MinorMax] = temp;

			}
		}

		this->save();
		cout << "排序成功，排序后结果为:" << endl;
		this->show_Renshu();

	}
}

//清空文件
void WorkerManager::clean_FILE()
{

	cout << "您确定清空数据吗？" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_Renshuarray != NULL)
		{
			for (int i = 0; i < this->m_Renshu; i++)
			{
				delete m_Renshuarray[i];
				m_Renshuarray[i] = NULL;
			}

			delete[] m_Renshuarray;
			m_Renshuarray = NULL;
			this->m_FileIsEmpty = true;
			this->m_Renshu = 0;
		}

		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
	}

	if (select == 2)
	{
		cout << "取消成功！" << endl;

		system("pause");
		
		system("cls");
	
	}

}


WorkerManager::~WorkerManager()
{
	if (this->m_Renshuarray != NULL)
	{
		for (int i = 0; i < this->m_Renshu; i++)
		{
			if (this->m_Renshuarray[i] != NULL)
			{
				delete this->m_Renshuarray[i];
			}

		}
	}
	delete[]this->m_Renshuarray;
	this->m_Renshuarray = NULL;
}