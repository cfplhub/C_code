#define _CRT_SERCURE_NO_WARININGS
#include<stdio.h>

void find_singel_num(int arr[], int sz, int* num1, int* num2)
{
	int i = 0;
	int ret = 0;
	//1�����
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}

	//2������ret�����������ұߵĵڼ�λ��1��
	int pos = 0;
	for (pos = 0; pos < 32; pos++)
	{
		if (((ret >> pos) & 1) == 1)
		{
			break;
		}
	}

	*num1 = *num2 = 0;
	//����
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*num1 ^= arr[i];
		}
		else
		{
			*num2 ^= arr[i];
		}
	}

}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	int num1, num2 = 0;

	find_singel_num(arr, sz, &num1, &num2);

	printf("%d %d", num1, num2);


	return 0;
}

//#include<stdio.h>
//
//void find_single_num(int arr[], int sz, int* num1, int* num2) {
//	int i;
//	int ret = 0;
//	// 1�����
//	for (i = 0; i < sz; i++) {
//		ret ^= arr[i];
//	}
//
//	// 2������ret�����ұߵĵ�1λ��1
//	int pos = 0;
//	while (!(ret & 1)) {
//		ret >>= 1;
//		pos++;
//	}
//
//	// 3������num1��num2
//	*num1 = *num2 = 0;
//	for (i = 0; i < sz; i++) {
//		if (((arr[i] >> pos) & 1) == 1) {
//			*num1 ^= arr[i];
//		}
//		else {
//			*num2 ^= arr[i];
//		}
//	}
//}
//
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num1, num2;
//
//	find_single_num(arr, sz, &num1, &num2);
//
//	printf("%d %d", num1, num2);
//	return 0;
//}