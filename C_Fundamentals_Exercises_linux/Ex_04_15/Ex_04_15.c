#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// input: 1 22 33 4 5 6
	int num1, num2, num3, num4, num5, num6;

	printf("Enter 6 integer numbers: ");
	scanf("%d%d%d%d%d%d%*c", &num1, &num2, &num3, &num4, &num5, &num6);

	printf("%2d\t%2d\n", num1, num2);
	printf("%2d\t%2d\n", num3, num4);
	printf("%2d\t%2d\n", num5, num6);

	return 0;
}