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
	worker = new Jingli(1, "赵丽", 1);
	worker->showInfo();
	delete worker;

	worker = new Yuangong(2, "奥巴马", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "安备近似", 2);
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
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.ExistSystem();
			break;

		case 1: //添加职工
			wm.Add_Renshu();
			break;

		case 2: //显示职工
			wm.show_Renshu();
			break;

		case 3: //删除职工
		//{
		//	int ret = wm.isexist(5);
		//	if (ret != -1)
		//	{
		//	cout << "职工存在" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工不存在" << endl;
		//	}

		//	system("pause");
		//	system("cls");
		//	break;
		//}

			wm.Del_renshu();
			break;

		case 4: //修改职工
			wm.mod_Zhigong();
			break;

		case 5: //查找职工
			wm.find_Zhigong();
			break;

		case 6: //排序职工
			wm.Sort_Zhigong();
			break;

		case 7: //清理文件
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