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

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExistSystem();

	//��¼ְ������
	int m_Renshu;

	//ְ������ָ��
	worker ** m_Renshuarray;

	//���ְ��
	void Add_Renshu();

	//�����ļ�
	void save();

	//ͳ������
	int get_Renshu();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//��ʼ������
	void init_Renshu();

	//��ʾְ��
	void show_Renshu();

	//�ж��Ƿ����
	int isExist(int id);

	//���������ж��Ƿ����
	int isExist2(string name);

	//ɾ��ְ��
	void Del_renshu();

	//�޸�ְ��
	void mod_Zhigong();

	//����ְ��
	void find_Zhigong();

	//����ְ��
	void Sort_Zhigong();

	//����ļ�
	void clean_FILE();




	~WorkerManager();

	

};