#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w+");
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//
//	//д�ļ�
//	//fputc('a', pf);
//	char i = 0;
//
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

int main()
{
	FILE* pf = fopen("test.txt", "r+");

	//���ļ�

	int ch = 0;
	//while ((ch = fgetc(pf)) != EOF)
	//{
	//	printf("%c ", ch);
	//}

	//���ļ�
	//��λ�ļ�ָ��
	fseek(pf, 2, SEEK_SET);

	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, 5, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	printf("%d\n", ftell(pf));//�ļ�ָ��ƫ����

	fseek(pf, -1, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);

	//��ָ��ص���ʼλ��

	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);


	//�ر��ļ�
	fclose(pf);
	pf = NULL;




	return 0;
}


//int main()
//
//{
//	//д�ļ�
//	FILE* pf = fopen("c.txt", "w");
//
//	if (pf == NULL)
//	{
//		perror("fpoen");
//		return 1;
//	}
//
//	fputs("hello world", pf);
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//
//
//}


//int main()
//
//{
//	//���ļ�
//	FILE* pf = fopen("c.txt", "r");
//
//	if (pf == NULL)
//	{
//		perror("fpoen");
//		return 1;
//	}
//
//	char arr[20];
//
//	fgets(arr, 5, pf);
//
//	printf("%s\n", arr);
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//
//
//}
//




//int main()
//{
//	FILE* pf = fopen("test1.txt", "w+");
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	char ch[] = "abcdefhrgjro";
//
//	//д�ļ�
//	fputs("ch", pf);
//
//
//
//	fclose(pf);
//	pf = NULL;
//
//
//
//	return 0;
//}



//struct S
//{
//	char  name[20];
//	int age;
//	float socer;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",18,88.2f };
//
//
//
//
//	FILE* pf = fopen("a.txt", "w");
//
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//д�ļ�
//
//	fprintf(pf, "%s %d %.2f", s.name, s.age, s.socer);
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//	return 0;
//}


//struct S
//{
//	char  name[20];
//	int age;
//	float socer;
//};
//
//int main()
//{
//	struct S s = { 0 };
//
//
//	FILE* pf = fopen("a.txt", "r");
//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//���ļ�
//
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.socer));
//
//	//printf("%s %d %f\n", s.name, s.age, s.socer);
//	fprintf(stdout,"%s %d %.2f\n", s.name, s.age, s.socer);
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//	return 0;
//}


//struct S
//{
//	char  name[20];
//	int age;
//	float socer;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",18,88.2f };
//
//	//�Զ�����д�ļ�
//	FILE* pf = fopen("b.txt", "wb");
//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//������д�ļ�
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//	return 0;
//}


//struct S
//{
//	char  name[20];
//	int age;
//	float socer;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",18,88.2f };
//
//	//�Զ����ƶ��ļ�
//	FILE* pf = fopen("b.txt", "rb");
//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//�����ƶ��ļ�
//	fread(&s, sizeof(struct S), 1, pf);
//
//	printf("%s %d %.2f", s.name, s.age, s.socer);
//	 
//	fclose(pf);
//
//	pf = NULL;
//
//
//	return 0;
//}

//struct S
//{
//	char name[10];
//	int age;
//	float socer;
//};
//
//int main()
//{
//	char buf[40];
//	struct S s = { "zhangsan",18,20.2f };
//
//	//��һ����ʽ��������ת�����ַ���
//	sprintf(buf, "%s %d %f", s.name, s.age, s.socer);
//	printf("%s\n", buf);
//	struct S tmp;
//
//	//��һ���ַ���ת������ʽ������
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.socer));
//
//	printf("%s %d %f", tmp.name, tmp.age, tmp.socer);
//
//	return 0;
//}