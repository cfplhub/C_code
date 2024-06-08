#include"student.h"
#include"globalFile.h"


student::student()
{

}


student::student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void student::operMenu()
{
	cout << "��ӭѧ��:" << this->m_Name << "��¼!" << endl;
	cout << "\t\t  ��������������-----------------����---��-��\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |         1.����ԤԼ             |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |         2.�鿴�ҵ�ԤԼ         |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |         3.�鿴����ԤԼ         |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |         4.ȡ��ԤԼ             |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |         0.ע����¼             |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ������������������-��-----------����---��--����\n";

	cout << "��ѡ�����Ĳ���:" << endl;

}

void student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������!  "<<endl;
	cout << "��������Ҫ����ԤԼ��ʱ���:" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
			cin.clear(); // �������״̬
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		}
	}

	cout << "��������ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (1)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	//cout << "��ѡ�������" << endl;
	//cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	//cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	//cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;
	//cout << "4�Ż���������" << vCom[3].m_MaxNum << endl;

	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������" << vCom[i].m_MaxNum << endl;
	}

	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 4)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	cout << "ԤԼ�ɹ��������!" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " "; 
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	

	ofs.close();
	system("pause");
	system("cls");

}

void student::showMyOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	for (int i = 0; i < of.m_Size; i++)
	{
		if(atoi(of.orderDate[i]["stuId"].c_str())==this->m_Id)
		{
			cout << "ԤԼʱ��:  ��" << of.orderDate[i]["date"];
			cout << "  ԤԼʱ��:" << (of.orderDate[i]["interval"] == "1" ? "����" : "����");
			cout << "  ����:" << of.orderDate[i]["roomId"];
			string status = " ״̬:";
			if (of.orderDate[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.orderDate[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			else if (of.orderDate[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void student::showAllOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ����: ��" << of.orderDate[i]["date"];
		cout << "  ԤԼʱ��:" << (of.orderDate[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ�ţ�" << of.orderDate[i]["stuId"];
		cout << "  ������" << of.orderDate[i]["stuName"];
		cout << "  �������:" << of.orderDate[i]["roomId"];
		string status = " ״̬:";
		if (of.orderDate[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.orderDate[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.orderDate[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void student::cancelOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.orderDate[i]["stuId"].c_str()) == this->m_Id )
		{
			if (of.orderDate[i]["status"] == "1" || of.orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ� ��" << of.orderDate[i]["date"];
				cout << " ʱ��Σ�" << (of.orderDate[i]["interval"] == "1" ? "����" : "����");
				cout << " ������ţ�" << of.orderDate[i]["roomId"];
				string status = " ״̬:";
				if (of.orderDate[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.orderDate[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				
				cout << status << endl;

			} 
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				system("pause");
				system("cls");
				return;
			}
			else
			{
				of.orderDate[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;

	}

	system("pause");
	system("cls");
}