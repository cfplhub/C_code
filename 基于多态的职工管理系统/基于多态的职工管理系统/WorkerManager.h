#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"Boss.h"
#include"Jingli.h"
#include"yuangong.h"
#include<fstream>
#define FILENAME "mulu.txt"


class WorkerManager
{
public:

	
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExistSystem();

	//记录职工人数
	int m_Renshu;

	//职工数组指针
	worker ** m_Renshuarray;

	//添加职工
	void Add_Renshu();

	//保存文件
	void save();

	//统计人数
	int get_Renshu();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//初始化数组
	void init_Renshu();

	//显示职工
	void show_Renshu();

	//判断是否存在
	int isExist(int id);

	//按照姓名判断是否存在
	int isExist2(string name);

	//删除职工
	void Del_renshu();

	//修改职工
	void mod_Zhigong();

	//查找职工
	void find_Zhigong();

	//排序职工
	void Sort_Zhigong();

	//清空文件
	void clean_FILE();




	~WorkerManager();

	

};