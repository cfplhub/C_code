#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	char i = 0;
//
//	for (i = 'a'; i < 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	
//
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//
//	return 0;
//}

//文本文件形式
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int ch = 0;
//
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		
//		//printf("%c ", ch);
//		putchar(ch);
//		
//	}
//
//	puts("\n");
//
//	if (ferror(pf))
//	{
//		puts("I\O error when read\n");
//	}
//
//	else if (feof(pf))
//	{
//		puts("End Of File reached successfully\n");
//	}
//
//	fclose(pf);
//
//	pf = NULL;
//
//
//
//	return 0;
//}

//二进制形式

enum{SIZE = 5};
int main()
{
	int arr[SIZE] = { 1,2,3,4,5 };

	FILE* pf = fopen("ans.bin", "wb");

	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fwrite(arr, sizeof * arr, SIZE, pf);

	fclose(pf);
	pf = NULL;

	int brr[SIZE];

	pf = fopen("ans.bin", "rb");

	size_t ret_code = fread(brr, sizeof * brr, SIZE, pf);

	if (ret_code == SIZE)
	{
		puts("Arry reached sucessfully,contents:");
		
		for (int n = 0; n < SIZE; ++n)
		{
			printf("%d ", brr[n]);

		}
	}
	

	//putchar("\n");
	else
	{
		if (ferror(pf))
		{
			puts("Error reading text.bin\n");
		}

		else if (feof(pf))
		{
			puts("Error reading text.bin: unexpected End of File\n");
		}

	}
	
	fclose(pf);

	pf = NULL;
}