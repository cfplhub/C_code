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
//// �������ڽ��ַ����еĿո��滻Ϊ %20
//void replaceSpace(char* str, int length) 
//{
//    // ��ʼ��ָ��curָ���ַ����Ŀ�ʼ
//    char* cur = str;
//    // ��ʼ���ո������
//    int space_count = 0;
//
//    // �����ַ���������ո������
//    while (*cur) {
//        if (*cur == ' ') {
//            space_count++;
//        }
//        cur++;
//    }
//
//    // �����滻�ո����ַ�������
//    int end1 = length - 1; // ԭʼ�ַ�����ĩβ����
//    int end2 = length + 2 * space_count - 1; // �滻�ո����ַ�����ĩβ����
//
//    // �Ӻ���ǰ�滻�ո�
//    while (end1 != end2) {
//        if (str[end1] != ' ') 
//        {
//            // �����ǰ�ַ����ǿո�ֱ�Ӹ��Ƶ���λ��
//            str[end2--] = str[end1--];
//        }
//        else {
//            // �����ǰ�ַ��ǿո��滻Ϊ %20
//            str[end2--] = '0';
//            str[end2--] = '2';
//            str[end2--] = '%';
//            end1--; // �ƶ�����һ���ַ�
//        }
//    }
//}
//
//int main() {
//    // ����һ���㹻����������洢�滻����ַ���
//    char str[] = "We are happy.";
//    // ��ȡԭʼ�ַ����ĳ���
//    int length = strlen(str);
//    // ���ú����滻�ո�
//    replaceSpace(str, length);
//
//    // ��ӡ�滻����ַ���
//    printf("%s\n", str);
//
//    return 0;
//}

#include<stdio.h>
#includes<tring.h>
#include<stdlib.h>
void replaceSpace(char** str, int length) {
    // ����ո�����
    int space_count = 0;
    for (int i = 0; i < length; i++) {
        if ((*str)[i] == ' ') {
            space_count++;
        }
    }
    // �������ַ����ĳ���
    int new_length = length + 2 * space_count;
    char* new_str = (char*)malloc((new_length + 1) * sizeof(char)); // ��̬�������ַ����ռ�
    // �Ӻ���ǰ�滻�ո�
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
    new_str[new_length] = '\0'; // ȷ���ַ����� '\0' ��β
    // ����ָ��
    *str = new_str;
}
int main() {
    // ��̬����ԭʼ�ַ���
    char* str = (char*)malloc(16 * sizeof(char));
    strcpy(str, "We are happy.");
    int length = strlen(str);
    // ���ú����滻�ո�
    replaceSpace(&str, length);
    // ��ӡ�滻����ַ���
    printf("%s\n", str);
    // �ͷ��ڴ�
    free(str);
    return 0;
}