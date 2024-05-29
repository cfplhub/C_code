#include<iostream>
using namespace std;
#include<string>//string头文件
#define max 1000 //通讯录最大联系人数

struct Person //联系人结构体
{
	string Name;//姓名
	int Sex;//性别：1男，2女
	int Age;//年龄
	string Phone;//电话
	string Addr;//住址
};

struct Addressbooks//通讯录结构体
{
	Person personnumble[max];//通讯录中保存的联系人数组
	int numble = 0;//通讯录中人员个数
};

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(Addressbooks* abs)//添加通讯录人员信息函数
{
	if (abs->numble == max) //先判断通讯录人员是否已满
	{
		cout << "当前通讯录已满，无法添加" << endl;
		return;
	}
	//姓名
	string name;
	cout << "请输入姓名： " << endl;
	cin >> name;
	abs->personnumble[abs->numble].Name = name;
	//性别
	cout << "请输入性别： " << endl;
	cout << "1--男，2--女" << endl;
	int sex = 0;
	while (true)
	{
		//如果输入的是1 或者 2 可以退出循环，因为输入的是正确值
		//如果输入有误，重新输入
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personnumble[abs->numble].Sex = sex;
			break;//在循环语句中，作用是跳出当前的循环语句
		}
		cout << "输入有误，重新输入" << endl;
	}

	//年龄
	cout << "请输入年龄： " << endl;
	int age = 0;
	cin >> age;
	abs->personnumble[abs->numble].Age = age;

	//电话
	cout << "请输入联系电话： " << endl;
	string phone;
	cin >> phone;
	abs->personnumble[abs->numble].Phone = phone;

	//住址 
	cout << "请输入家庭住址： " << endl;
	string addr;
	cin >> addr;
	abs->personnumble[abs->numble].Addr = addr;

	//更新通讯录人数
	abs->numble++;
	cout << "联系人添加成功" << endl;

	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void showPerson(Addressbooks* abs)//显示通讯中所有的联系人信息
{
	//如果当前通讯录中没有人员，就提示记录为空，人数大于0时，显示通讯录中信息
	if (abs->numble == 0)
		cout << "当前记录为空" << endl;
	for (int i = 0; i < abs->numble; i++)
	{
		cout << "姓名: " << abs->personnumble[i].Name << "\t";
		cout << "性别: " << (abs->personnumble[i].Sex == 1 ? "男" : "女") << "\t"; //“==”优先级高于“？：”
		cout << "年龄: " << abs->personnumble[i].Age << "\t";
		cout << "电话: " << abs->personnumble[i].Phone << "\t";
		cout << "住址: " << abs->personnumble[i].Addr << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//判断用户输入的联系人是否存在，如果存在则执行删除操作，不存在则提示用户没有此联系人
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->numble; i++)
		if (abs->personnumble[i].Name == name)
			return i;//返回该联系人位置
	return -1;//没有找到该联系人 返回-1
}

void deletePerson(Addressbooks* abs) //删除联系人函数
{
	cout << "请输入删除联系人姓名：" << endl;
	string name;
	cin >> name;

	if (isExist(abs, name) != -1)
	{
		//找到该联系人
		for (int i = isExist(abs, name); i < abs->numble; i++)
		{
			abs->personnumble[i] = abs->personnumble[i + 1];//数据前移
			abs->numble--;//更新通讯录中的联系人数量
		}
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void findePerson(Addressbooks* abs)//查找指定联系人函数
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)//找到指定联系人
	{
		cout << "姓名: " << abs->personnumble[isExist(abs, name)].Name << "\t";
		cout << "性别: " << (abs->personnumble[isExist(abs, name)].Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personnumble[isExist(abs, name)].Age << "\t";
		cout << "电话: " << abs->personnumble[isExist(abs, name)].Phone << "\t";
		cout << "住址: " << abs->personnumble[isExist(abs, name)].Addr << endl;
	}
	else//未找到指定联系人
		cout << "查无此人" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作	 
}

void modifyPerson(Addressbooks* abs)//修改指定联系人函数
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)//找到指定联系人，并修改信息
	{
		//姓名
		string m_name;
		cout << "请输入姓名： " << endl;
		cin >> m_name;
		abs->personnumble[isExist(abs, name)].Name = m_name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1--男，2--女" << endl;
		int sex;
		while (true)
		{
			//如果输入的是1 或者 2 可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumble[isExist(abs, name)].Sex = sex;
				break;//在循环语句中，作用是跳出当前的循环语句
			}
			cout << "输入有误，重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personnumble[isExist(abs, name)].Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personnumble[isExist(abs, name)].Phone = phone;

		//住址 
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personnumble[isExist(abs, name)].Addr = address;

		cout << " 修改成功！" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void cleanPerson(Addressbooks* abs)
{
	int select = 0;
	cout << "是否确认清空通讯录？" << endl;
	cout << "1--确认，2--取消" << endl;
	while (true)
	{
		//如果输入的是1 或者 2 可以退出循环，因为输入的是正确值
		//如果输入有误，重新输入
		cin >> select;
		if (select == 1 || select == 2)
			break;//在循环语句中，作用是跳出当前的循环语句
		cout << "输入有误，重新输入" << endl;
	}
	if (select == 1)
	{
		abs->numble = 0;
		cout << "通讯录已清空" << endl;
	}
	else
		cout << "已取消清空通讯录" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

int main()
{
	Addressbooks abs;//创建通讯录结构体变量
	abs.numble = 0; //初始化通讯录当前人员个数

	int select = 0;//创建用户选择变量
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);//地址传递可以修改实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			findePerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");//按任意键退出系统
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}