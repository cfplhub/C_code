#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w+");
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//
//	//写文件
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
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

int main()
{
	FILE* pf = fopen("test.txt", "r+");

	//读文件

	int ch = 0;
	//while ((ch = fgetc(pf)) != EOF)
	//{
	//	printf("%c ", ch);
	//}

	//读文件
	//定位文件指针
	fseek(pf, 2, SEEK_SET);

	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, 5, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	printf("%d\n", ftell(pf));//文件指针偏移量

	fseek(pf, -1, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);

	//让指针回到起始位置

	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);


	//关闭文件
	fclose(pf);
	pf = NULL;




	return 0;
}


//int main()
//
//{
//	//写文件
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
//	//读文件
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
//	//写文件
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
//	//写文件
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
//	//读文件
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
//	//以二进制写文件
//	FILE* pf = fopen("b.txt", "wb");
//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制写文件
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
//	//以二进制读文件
//	FILE* pf = fopen("b.txt", "rb");
//
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制读文件
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
//	//把一个格式化的数据转换成字符串
//	sprintf(buf, "%s %d %f", s.name, s.age, s.socer);
//	printf("%s\n", buf);
//	struct S tmp;
//
//	//从一个字符串转化出格式化数据
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.socer));
//
//	printf("%s %d %f", tmp.name, tmp.age, tmp.socer);
//
//	return 0;
//}