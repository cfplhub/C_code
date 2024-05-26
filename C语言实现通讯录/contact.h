#pragma once
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100
#define MAXName 20
#define MAXSex 10
#define MAXAddr 30
#define MAXTele 15


//人员信息
typedef struct PeoInfo
{
	char name[MAXName];
	char sex[MAXSex];
	int age;
	char addr[MAXAddr];
	char tele[MAXTele];
}PeoInfo;

//通讯录实现
typedef struct Contact
{
	PeoInfo data [100];//存放人的数据
	int count; //现有通讯录人数

}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//添加通讯录
void AddContact(Contact* pc);

//展示通讯录
void ShowContact(Contact* pc);

//删除指定通讯录
void DeleContact(Contact* pc);

//查找联系人
void FindContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//排序通讯录
void SortContact(Contact* pc);