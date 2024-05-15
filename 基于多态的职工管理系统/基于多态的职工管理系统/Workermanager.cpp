#include"WorkerManager.h";

#include<iostream>
using namespace std;


WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	 
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;

		this->m_Renshu = 0;

		this->m_Renshuarray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;

	}


		char ch;
		ifs >> ch;
		if (ifs.eof())//eof�ļ�β��
		{
			//�ļ�Ϊ��
	      //cout<<"�ļ�Ϊ��"<<endl;
			//��ʼ������
			//��ʼ����¼����
			this->m_Renshu = 0;
			//��ʼ������ָ��
			this->m_Renshuarray = NULL;
			//��ʼ���ļ��Ƿ�Ϊ��
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
			
		}


		//3.�ļ����ڣ���������
		int num = this->get_Renshu();
		//cout << "ְ������Ϊ��" << num << endl;
		this->m_Renshu = num;

		//���ٿռ�
		this->m_Renshuarray = new worker * [this->m_Renshu];

		//���ļ��е����ݣ�����������
		this->init_Renshu();

		//for (int i=0;i<m_Renshu;i++)
		//{
		//  cout << "ְ����ţ�" << this->m_Renshuarray[i]->m_Id
		//      << "ְ��������" << this->m_Renshuarray[i]->m_Name
		//      << "ְ����ţ�" << this->m_Renshuarray[i]->m_DepId << endl;
		//}

}


void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "*****��ӭʹ��ְ������ϵͳ*****" << endl;
	cout << "*******0-�˳��������*********" << endl;
	cout << "*******1-����ְ����Ϣ*********" << endl;
	cout << "*******2-��ʾְ����Ϣ*********" << endl;
	cout << "*******3-ɾ����ְְ��*********" << endl;
	cout << "*******4-�޸�ְ����Ϣ*********" << endl;
	cout << "*******5-����ְ����Ϣ*********" << endl;
	cout << "*******6-���ձ������*********" << endl;
	cout << "*******7-��������ĵ�*********" << endl;
	cout << "******************************" << endl;
	
}

void WorkerManager::ExistSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

//���ְ��
void WorkerManager::Add_Renshu()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_Renshu + addnum;

		//�����¿ռ�
		worker** newspace = new worker * [newSize];



		//��ԭ���ռ������ݣ��������¿ռ�
		if (this->m_Renshuarray != NULL)
		{
			for (int i = 0; i < this->m_Renshu; i++)
			{
				newspace[i] = this->m_Renshuarray[i];
			}
		}

		//�������������
		for (int i = 0; i < addnum; i++)
		{
			int id = 0;
			string name;
			int dSelect;


			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "�������ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

		//�ͷ�ԭ�пռ�
		delete[] this->m_Renshuarray;

		this->m_Renshuarray = newspace;

		this->m_Renshu = newSize;

		//�ļ���Ϊ��
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addnum << "����ְ��" << endl;

		this->save();
	}
		else
		{
			cout << "������������" << endl;
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


//��ʾְ��
void WorkerManager::show_Renshu()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
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

//�ж�ְ���Ƿ����
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





//ɾ��ְ��
void WorkerManager::Del_renshu()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}

	else
	{
		cout << "��������Ҫɾ����ְ�����" << endl;

		int id = 0;

		cin >> id;

		int index = this->isExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_Renshu - 1; i++)
			{
				this->m_Renshuarray[i] = this->m_Renshuarray[i + 1];
			}

			//���������м�¼��Ա����
			this->m_Renshu--;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;

		}
		
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�ְ��" << endl;
		}
	
		
	}
	system("pause");
	system("cls");
}


//���������ж��Ƿ����
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
//		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
//	}
//
//	else
//	{
//		cout << "��������Ҫɾ��ְ���ķ�ʽ��" << endl;
//		cout << "1������ְ�����ɾ��" << endl;
//		cout << "2������ְ������ɾ��" << endl;
//
//		int select = 0;
//		cin >> select;
//
//		if (select == 1)
//		{
//			cout << "��������Ҫɾ����ְ�����" << endl;
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
//				//���������м�¼��Ա����
//				this->m_Renshu--;
//				//����ͬ�����µ��ļ���
//				this->save();
//				cout << "ɾ���ɹ�" << endl;
//
//			}
//
//			else
//			{
//				cout << "ɾ��ʧ�ܣ�δ�ҵ�ְ��" << endl;
//			}
//
//
//		}
//
//		else if (select == 2)
//		{
//			cout << "��������Ҫɾ����ְ������" << endl;
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
//					//���������м�¼��Ա����
//					this->m_Renshu--;
//
//					//����ͬ�����µ��ļ���
//					this->save();
//
//					cout << "ɾ���ɹ�" << endl;
//					flag = true;
//				}
//			}
//
//			if (flag == false)
//			{
//				cout << "���޴��ˣ�ɾ��ʧ��" << endl;
//			}
//		}
//
//		system("pause");
//		system("cls");
//		
//	}
//	
//}


//�޸�ְ��
void WorkerManager::mod_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	else
	{
		cout << "��������Ҫ�޸�ְ���ı��" << endl;

		int id;
		cin >> id;

		int ret = this->isExist(id);

		if (ret != -1)
		{
			delete this->m_Renshuarray[ret];

			int newid;
			string newname = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "��������������" << endl;
			cin >> newname;

			cout << "��������ְ�����ű�ţ�" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
	
		}

		else
		{
			cout << "���޴��ˣ�����������" << endl;

		}

	}
	system("pause");
	system("cls");

}

//����ְ��
void WorkerManager::find_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	else
	{
		cout << "��������Ҫ����ְ����ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "��������Ҫ���ҵ�ְ�����" << endl;
			int id;
			cin >> id;

			int ret = this->isExist(id);

			if (ret != -1)
			{
				cout << "Ϊ���ҵ�" << id << "��ְ������ְ����Ϣ���£�" << endl;

				this->m_Renshuarray[ret]->showInfo();
			}

			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}

		else if (select == 2)
		{
			cout << "��������Ҫ����ְ����������" << endl;
			string name;
			cin >> name;
			
			bool flag = false;

			for(int i=0;i<this->m_Renshu;i++)
			{ 
				if (this->m_Renshuarray[i]->m_Name == name)
				{
					cout << "���ҳɹ���Ϊ���ҵ�" 
						 << this->m_Renshuarray[i]->m_Id 
						 << "��ְ������Ϣ���£�" << endl;

					flag = true;

					this->m_Renshuarray[i]->showInfo();
				}


			}
			
			if (flag == false )
			{
				cout << "���޴��ˣ�����ʧ��" << endl;
			}
		}
	}

	
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Sort_Zhigong()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

		system("pause");
		system("cls");
	}

	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������ְ���Ž�������" << endl;
		cout << "2������ְ���Ž��н���" << endl;

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
					cout << "�����������������룡" << endl;

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
		cout << "����ɹ����������Ϊ:" << endl;
		this->show_Renshu();

	}
}

//����ļ�
void WorkerManager::clean_FILE()
{

	cout << "��ȷ�����������" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

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

		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");
	}

	if (select == 2)
	{
		cout << "ȡ���ɹ���" << endl;

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