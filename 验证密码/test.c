#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char password[20] = { 0 };
	int i = 0;

	for(i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password);

		if (strcmp(password, "abcdef") == 0)
		{
			printf("����������ȷ����½�ɹ���\n");
			break;
		}

		else
		{
			printf("�����������������%d�λ����������룡\n", 2 - i);
		}
	}

	if (i == 3)
	{
		printf("��½ʧ�ܣ�\n������ϵͳ�������룡\n");
	}

	return 0;

}