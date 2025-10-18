#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short int a, b;

	a = 0x5A03; // 0101 1010 0000 0011 = 23043
	b = 0xCF83; // 1100 1111 1000 0011

	printf("size of short int = %d\n", sizeof(short int));
	printf("hex: a = %x\ndec: a = %d\n", a, a);
	printf("b = %x\n\n", b);
	printf("~a = %x\n", ~a);	//1010 0101 1111 1100 voorafgegaan door 2 bytes FF
	printf("a & b = %x\n", a & b); //0100 1010 0000 0011
	printf("a | b = %8x\n", a | b); //1101 1111 1000 0011
	printf("a ^ b = %8x\n", a ^ b); //1001 0101 1000 0000
	printf("a>>4 = %8x\n", a >> 4);	//0000 0101 1010 0000
	printf("a<<4 = %8x\n\n", a << 4);	//0101 1010 0000 0011 0000
	return 0;
}
