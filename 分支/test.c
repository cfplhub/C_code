#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int month, year;
	float money = 200;

	printf("���������Ĺ�Ʊ�·ݣ�");
	
		while (1)
		{
			scanf("%d", &month);
			if (month <= 0 || month > 12)
			{
				printf("��������ȷ���·ݣ�\n");
			
			}


			else if (month > 0 && month <= 12)
			{
				break;
			}
			
		}
	
		printf("�������������䣺");
		scanf("%d", &year);
	
		if (month < 5 || month>10)
		{
			money = money * 0.8;
		}
		if (year >= 65)
		{
			money = 0;
		}
	
		else if (year < 14)
		{
			money = money / 2;
		}

		

		printf("����֧����Ʊ��Ϊ��%0.2f\n", money);


	return 0;

}