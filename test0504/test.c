#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	
//	pa++;
//
//	printf("%s\n", *pa);
//
//
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//
//	char*** cpp = cp;
//
//	printf("%s\n",**++cpp );
//	printf("%s\n",*--*++cpp+3 );
//	printf("%s\n",*cpp[-2]+3);
//	printf("%s\n", cpp[-1][-1]+1);
//
//
//	return 0;
//}

//模拟字符串拷贝
char* my_strcopy(char* str2, const char* str1)
{

	assert(str2 && str1);//断言，参数不能为空指针

	char* ret = *str2;

	//while (*str1)
	//{
	//	*str2++ = *str1++;

	//}

	//*str2 = *str1;//\0

	while (*str2++ = *str1++)
	{
		;

	}

	return ret;
}


//模拟字符串追加
char* mystrcat(char* des, const char* src)
{
	assert(des && src);//断言，参数不能为空指针

	char* ret = des;

	while (*des != '\0')//找到\0
	{
		des++;
	}

	while (*des++ = *src++)//追加字符串
		;

	return ret;
}

//int main()
//{
//
//	//char str1[] = "abcdef";
//	//char str2[20] = { 0 };
//
//	//my_strcopy(str2, str1);
//
//	//printf("%s\n", str2);
//
//	char arr[] = { "hello " };
//
//	char arr2[] = { "world" };
//
//	mystrcat(arr, arr2);
//
//	printf("%s\n", arr);
//
//}

//模拟字符串比较
//两字符对应ASCII码值，相等跳过
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//断言，参数不能为空指针
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//
//		str1++;
//		str2++;
//	}
//
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//断言，参数不能为空指针
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//
//		str1++;
//		str2++;
//	}
//
//	return *str1 - *str2;
//
//}
//
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abc";
//
//	int ret = my_strcmp(arr1, arr2);
//
//	if (ret > 0)
//		printf(">\n");
//	else if (ret == 0)
//		printf("==\n");
//	else
//		printf("<\n");
//
//	return 0;
//
//}


//模拟字符串找子字符串
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//
//		if (*s2 == '\0')
//		{
//			return (char*)p;
//		}
//
//		p++;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	char arr[] = "github.com/cfplhub";
//	char arr2[] = "cfplhub";
//
//	char* ret = my_strstr(arr, arr2);
//
//	if (ret == NULL)
//		printf("字符串不存在！\n");
//
//	else
//	    printf("%s\n", ret);
//
//	return 0;
//}

//模拟内存拷贝
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//
//		*(char*)dest += 1;
//		*(char*)src += 1;
//
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//
//	int arr2[] = { 0 };
//
//	int* ret = my_memcpy(arr2, arr, 20);
//
//
//	return 0;
//}

//模拟实现memmove(即使两参数内容重叠也能拷贝)目标内存与源内存可重叠

void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);

	void* ret = dest;

	if (dest < src)
	{
		//前->后 拷贝
		while (num--)
		{
			*(char*)dest = *(char*)src;
		
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}

	}

	else
	{
		//后->前  拷贝

		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	my_memmove(arr, arr + 2, 20);

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}