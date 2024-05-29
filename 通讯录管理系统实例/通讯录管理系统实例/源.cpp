#include<iostream>
using namespace std;
#include<string>//stringͷ�ļ�
#define max 1000 //ͨѶ¼�����ϵ����

struct Person //��ϵ�˽ṹ��
{
	string Name;//����
	int Sex;//�Ա�1�У�2Ů
	int Age;//����
	string Phone;//�绰
	string Addr;//סַ
};

struct Addressbooks//ͨѶ¼�ṹ��
{
	Person personnumble[max];//ͨѶ¼�б������ϵ������
	int numble = 0;//ͨѶ¼����Ա����
};

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(Addressbooks* abs)//���ͨѶ¼��Ա��Ϣ����
{
	if (abs->numble == max) //���ж�ͨѶ¼��Ա�Ƿ�����
	{
		cout << "��ǰͨѶ¼�������޷����" << endl;
		return;
	}
	//����
	string name;
	cout << "������������ " << endl;
	cin >> name;
	abs->personnumble[abs->numble].Name = name;
	//�Ա�
	cout << "�������Ա� " << endl;
	cout << "1--�У�2--Ů" << endl;
	int sex = 0;
	while (true)
	{
		//����������1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
		//�������������������
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personnumble[abs->numble].Sex = sex;
			break;//��ѭ������У�������������ǰ��ѭ�����
		}
		cout << "����������������" << endl;
	}

	//����
	cout << "���������䣺 " << endl;
	int age = 0;
	cin >> age;
	abs->personnumble[abs->numble].Age = age;

	//�绰
	cout << "��������ϵ�绰�� " << endl;
	string phone;
	cin >> phone;
	abs->personnumble[abs->numble].Phone = phone;

	//סַ 
	cout << "�������ͥסַ�� " << endl;
	string addr;
	cin >> addr;
	abs->personnumble[abs->numble].Addr = addr;

	//����ͨѶ¼����
	abs->numble++;
	cout << "��ϵ����ӳɹ�" << endl;

	system("pause");//�밴���������
	system("cls");//��������
}

void showPerson(Addressbooks* abs)//��ʾͨѶ�����е���ϵ����Ϣ
{
	//�����ǰͨѶ¼��û����Ա������ʾ��¼Ϊ�գ���������0ʱ����ʾͨѶ¼����Ϣ
	if (abs->numble == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	for (int i = 0; i < abs->numble; i++)
	{
		cout << "����: " << abs->personnumble[i].Name << "\t";
		cout << "�Ա�: " << (abs->personnumble[i].Sex == 1 ? "��" : "Ů") << "\t"; //��==�����ȼ����ڡ�������
		cout << "����: " << abs->personnumble[i].Age << "\t";
		cout << "�绰: " << abs->personnumble[i].Phone << "\t";
		cout << "סַ: " << abs->personnumble[i].Addr << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�ж��û��������ϵ���Ƿ���ڣ����������ִ��ɾ������������������ʾ�û�û�д���ϵ��
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->numble; i++)
		if (abs->personnumble[i].Name == name)
			return i;//���ظ���ϵ��λ��
	return -1;//û���ҵ�����ϵ�� ����-1
}

void deletePerson(Addressbooks* abs) //ɾ����ϵ�˺���
{
	cout << "������ɾ����ϵ��������" << endl;
	string name;
	cin >> name;

	if (isExist(abs, name) != -1)
	{
		//�ҵ�����ϵ��
		for (int i = isExist(abs, name); i < abs->numble; i++)
		{
			abs->personnumble[i] = abs->personnumble[i + 1];//����ǰ��
			abs->numble--;//����ͨѶ¼�е���ϵ������
		}
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}

void findePerson(Addressbooks* abs)//����ָ����ϵ�˺���
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)//�ҵ�ָ����ϵ��
	{
		cout << "����: " << abs->personnumble[isExist(abs, name)].Name << "\t";
		cout << "�Ա�: " << (abs->personnumble[isExist(abs, name)].Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personnumble[isExist(abs, name)].Age << "\t";
		cout << "�绰: " << abs->personnumble[isExist(abs, name)].Phone << "\t";
		cout << "סַ: " << abs->personnumble[isExist(abs, name)].Addr << endl;
	}
	else//δ�ҵ�ָ����ϵ��
		cout << "���޴���" << endl;
	system("pause");//�밴���������
	system("cls");//��������	 
}

void modifyPerson(Addressbooks* abs)//�޸�ָ����ϵ�˺���
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)//�ҵ�ָ����ϵ�ˣ����޸���Ϣ
	{
		//����
		string m_name;
		cout << "������������ " << endl;
		cin >> m_name;
		abs->personnumble[isExist(abs, name)].Name = m_name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1--�У�2--Ů" << endl;
		int sex;
		while (true)
		{
			//����������1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumble[isExist(abs, name)].Sex = sex;
				break;//��ѭ������У�������������ǰ��ѭ�����
			}
			cout << "����������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personnumble[isExist(abs, name)].Age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personnumble[isExist(abs, name)].Phone = phone;

		//סַ 
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personnumble[isExist(abs, name)].Addr = address;

		cout << " �޸ĳɹ���" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}

void cleanPerson(Addressbooks* abs)
{
	int select = 0;
	cout << "�Ƿ�ȷ�����ͨѶ¼��" << endl;
	cout << "1--ȷ�ϣ�2--ȡ��" << endl;
	while (true)
	{
		//����������1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
		//�������������������
		cin >> select;
		if (select == 1 || select == 2)
			break;//��ѭ������У�������������ǰ��ѭ�����
		cout << "����������������" << endl;
	}
	if (select == 1)
	{
		abs->numble = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else
		cout << "��ȡ�����ͨѶ¼" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}

int main()
{
	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.numble = 0; //��ʼ��ͨѶ¼��ǰ��Ա����

	int select = 0;//�����û�ѡ�����
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);//��ַ���ݿ����޸�ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			findePerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//��������˳�ϵͳ
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}