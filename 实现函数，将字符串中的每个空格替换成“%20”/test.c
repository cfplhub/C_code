#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//
//
//void replaceSpace(char* str, int length)
//{
//	char* cur = str;
//	int space_count = 0;
//	while (*cur)
//	{
//		if (*cur == ' ')
//		{
//			space_count++;
//		}
//
//		cur++;
//	}
//
//	int end1 = length - 1;
//	int end2 = length + 2 * space_count - 1;
//
//	while (end1 != end2)
//	{
//		if (str[end1] != ' ')
//		{
//			str[end2--] = str[end1--];
//		}
//
//		else
//		{
//			end1--;
//			str[end2--] = '0';
//			str[end2--] = '2';
//			str[end2--] = '%';
//
//		}
//	}
//
//}
//
//int main()
//{
//	char str[] = "We are happy.";
//
//	int length = strlen(str);
//	replaceSpace(str, length);
//
//	printf("%s\n", str);
//
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//// 函数用于将字符串中的空格替换为 %20
//void replaceSpace(char* str, int length) 
//{
//    // 初始化指针cur指向字符串的开始
//    char* cur = str;
//    // 初始化空格计数器
//    int space_count = 0;
//
//    // 遍历字符串，计算空格的数量
//    while (*cur) {
//        if (*cur == ' ') {
//            space_count++;
//        }
//        cur++;
//    }
//
//    // 计算替换空格后的字符串长度
//    int end1 = length - 1; // 原始字符串的末尾索引
//    int end2 = length + 2 * space_count - 1; // 替换空格后的字符串的末尾索引
//
//    // 从后向前替换空格
//    while (end1 != end2) {
//        if (str[end1] != ' ') 
//        {
//            // 如果当前字符不是空格，直接复制到新位置
//            str[end2--] = str[end1--];
//        }
//        else {
//            // 如果当前字符是空格，替换为 %20
//            str[end2--] = '0';
//            str[end2--] = '2';
//            str[end2--] = '%';
//            end1--; // 移动到下一个字符
//        }
//    }
//}
//
//int main() {
//    // 定义一个足够大的数组来存储替换后的字符串
//    char str[] = "We are happy.";
//    // 获取原始字符串的长度
//    int length = strlen(str);
//    // 调用函数替换空格
//    replaceSpace(str, length);
//
//    // 打印替换后的字符串
//    printf("%s\n", str);
//
//    return 0;
//}

#include<stdio.h>
#includes<tring.h>
#include<stdlib.h>
void replaceSpace(char** str, int length) {
    // 计算空格数量
    int space_count = 0;
    for (int i = 0; i < length; i++) {
        if ((*str)[i] == ' ') {
            space_count++;
        }
    }
    // 计算新字符串的长度
    int new_length = length + 2 * space_count;
    char* new_str = (char*)malloc((new_length + 1) * sizeof(char)); // 动态分配新字符串空间
    // 从后向前替换空格
    int end1 = length - 1;
    int end2 = new_length - 1;
    while (end1 >= 0) {
        if ((*str)[end1] != ' ') {
            new_str[end2--] = (*str)[end1--];
        }
        else {
            new_str[end2--] = '0';
            new_str[end2--] = '2';
            new_str[end2--] = '%';
            end1--;
        }
    }
    new_str[new_length] = '\0'; // 确保字符串以 '\0' 结尾
    // 更新指针
    *str = new_str;
}
int main() {
    // 动态分配原始字符串
    char* str = (char*)malloc(16 * sizeof(char));
    strcpy(str, "We are happy.");
    int length = strlen(str);
    // 调用函数替换空格
    replaceSpace(&str, length);
    // 打印替换后的字符串
    printf("%s\n", str);
    // 释放内存
    free(str);
    return 0;
}