#pragma once
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100
#define MAXName 20
#define MAXSex 10
#define MAXAddr 30
#define MAXTele 15


//��Ա��Ϣ
typedef struct PeoInfo
{
	char name[MAXName];
	char sex[MAXSex];
	int age;
	char addr[MAXAddr];
	char tele[MAXTele];
}PeoInfo;

//ͨѶ¼ʵ��
typedef struct Contact
{
	PeoInfo data [100];//����˵�����
	int count; //����ͨѶ¼����

}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//���ͨѶ¼
void AddContact(Contact* pc);

//չʾͨѶ¼
void ShowContact(Contact* pc);

//ɾ��ָ��ͨѶ¼
void DeleContact(Contact* pc);

//������ϵ��
void FindContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//����ͨѶ¼
void SortContact(Contact* pc);