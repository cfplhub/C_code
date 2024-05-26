#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;

	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count > MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}

	printf("���������֣�->");
	scanf("%s", pc->data[pc->count].name);

	printf("�������Ա�->");
	scanf("%s", pc->data[pc->count].sex);

	printf("���������䣺->");
	scanf("%d", &(pc->data[pc->count].age));

	printf("�������ַ��->");
	scanf("%s", pc->data[pc->count].addr);

	printf("������绰��->");
	scanf("%s", pc->data[pc->count].tele);

	//ͨѶ¼���� +1
	pc->count++;

	printf("��ӳɹ���\n");

	system("pause");
	system("cls");
}

void ShowContact(const Contact* pc)
{
	assert(pc);

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "��ַ", "�绰\n");

	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-15s\t%-30s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age, 
			pc->data[i].addr,
			pc->data[i].tele);
	}

	system("pause");
	system("cls");

}

//��̬����  ��ĺ������ܵ���
static int SearchByname(Contact* pc, char name[MAXName])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}

	return -1;
}

void DeleContact(Contact* pc)
{
	assert(pc);
	int i = 0;

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ҫɾ�����ˣ�\n");
		system("pause");
		system("cls");
		return;
	}

	char name[MAXName] = { 0 };
	printf("��������Ҫɾ�����˵����֣�->");

	scanf("%s", name);

	//����
	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("��Ҫɾ�����˲����ڣ�\n");
		system("pause");
		system("cls");
		return;
	}

	//ɾ��
	for (i = pos; i < pc->count - 1; i++)
	{
		//����
		pc->data[i] = pc->data[i + 1];
		
	}

	pc->count--;

	printf("ɾ���ɹ���\n");
	system("pause");
	system("cls");
}

void FindContact(Contact* pc)
{
	assert(&pc);

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û��������Ҫ���ˣ�\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	char name[MAXName] = { 0 };

	printf("��������Ҫ���ҵ��˵����֣�->");

	scanf("%s", name);

	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("��Ҫ���ҵ��˲����ڣ�\n");
		system("pause");
		system("cls");
		return;
	}

	printf("���ҳɹ���\n");

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "��ַ", "�绰\n");

	printf("%-20s\t%-5s\t%-5d\t%-15s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].addr,
		pc->data[pos].tele);

	system("pause");
	system("cls");

}

//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	assert(&pc);

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ҫ�޸ĵ��ˣ�\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	char name[MAXName] = { 0 };

	printf("��������Ҫ�޸ĵ��˵����֣�->");

	scanf("%s", name);

	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ��˲����ڣ�\n");
		system("pause");
		system("cls");
		return;
	}

	printf("�������޸����֣�->");
	scanf("%s", pc->data[pos].name);

	printf("�������޸��Ա�->");
	scanf("%s", pc->data[pos].sex);

	printf("�������޸����䣺->");
	scanf("%d", &(pc->data[pos].age));

	printf("�������޸ĵ�ַ��->");
	scanf("%s", pc->data[pos].addr);

	printf("�������޸ĵ绰��->");
	scanf("%s", pc->data[pos].tele);

	printf("�޸ĳɹ���\n");

	ShowContact(pc);


}

int cmp_peo_by_name(const void* elem1, const void* elem2)
{
	return strcmp( ( *(PeoInfo* )elem1).name, (*(PeoInfo*)elem2).name );

}

//����ͨѶ¼
void SortContact(Contact* pc)
{
	assert(&pc);

	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	
	printf("����ɹ�\n");

	system("pause");
	system("cls");
}