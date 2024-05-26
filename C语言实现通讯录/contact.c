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
		printf("通讯录已满，无法添加\n");
		return;
	}

	printf("请输入名字：->");
	scanf("%s", pc->data[pc->count].name);

	printf("请输入性别：->");
	scanf("%s", pc->data[pc->count].sex);

	printf("请输入年龄：->");
	scanf("%d", &(pc->data[pc->count].age));

	printf("请输入地址：->");
	scanf("%s", pc->data[pc->count].addr);

	printf("请输入电话：->");
	scanf("%s", pc->data[pc->count].tele);

	//通讯录人数 +1
	pc->count++;

	printf("添加成功！\n");

	system("pause");
	system("cls");
}

void ShowContact(const Contact* pc)
{
	assert(pc);

	if (pc->count == 0)
	{
		printf("通讯录为空！\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-30s\n", "名字", "性别", "年龄", "地址", "电话\n");

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

//静态函数  别的函数不能调用
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
		printf("通讯录为空，没有您要删除的人！\n");
		system("pause");
		system("cls");
		return;
	}

	char name[MAXName] = { 0 };
	printf("请输入您要删除的人的名字：->");

	scanf("%s", name);

	//查找
	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("您要删除的人不存在！\n");
		system("pause");
		system("cls");
		return;
	}

	//删除
	for (i = pos; i < pc->count - 1; i++)
	{
		//覆盖
		pc->data[i] = pc->data[i + 1];
		
	}

	pc->count--;

	printf("删除成功！\n");
	system("pause");
	system("cls");
}

void FindContact(Contact* pc)
{
	assert(&pc);

	if (pc->count == 0)
	{
		printf("通讯录为空，没有您查找要的人！\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	char name[MAXName] = { 0 };

	printf("请输入您要查找的人的名字：->");

	scanf("%s", name);

	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("您要查找的人不存在！\n");
		system("pause");
		system("cls");
		return;
	}

	printf("查找成功！\n");

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-30s\n", "名字", "性别", "年龄", "地址", "电话\n");

	printf("%-20s\t%-5s\t%-5d\t%-15s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].addr,
		pc->data[pos].tele);

	system("pause");
	system("cls");

}

//修改联系人
void ModifyContact(Contact* pc)
{
	assert(&pc);

	if (pc->count == 0)
	{
		printf("通讯录为空，没有您要修改的人！\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;

	char name[MAXName] = { 0 };

	printf("请输入您要修改的人的名字：->");

	scanf("%s", name);

	int pos = SearchByname(pc, name);

	if (pos == -1)
	{
		printf("您要修改的人不存在！\n");
		system("pause");
		system("cls");
		return;
	}

	printf("请输入修改名字：->");
	scanf("%s", pc->data[pos].name);

	printf("请输入修改性别：->");
	scanf("%s", pc->data[pos].sex);

	printf("请输入修改年龄：->");
	scanf("%d", &(pc->data[pos].age));

	printf("请输入修改地址：->");
	scanf("%s", pc->data[pos].addr);

	printf("请输入修改电话：->");
	scanf("%s", pc->data[pos].tele);

	printf("修改成功！\n");

	ShowContact(pc);


}

int cmp_peo_by_name(const void* elem1, const void* elem2)
{
	return strcmp( ( *(PeoInfo* )elem1).name, (*(PeoInfo*)elem2).name );

}

//排序通讯录
void SortContact(Contact* pc)
{
	assert(&pc);

	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	
	printf("排序成功\n");

	system("pause");
	system("cls");
}