#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define SWAP_BIT(n)  (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))

int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d\n", SWAP_BIT(n));


   return 0;
}