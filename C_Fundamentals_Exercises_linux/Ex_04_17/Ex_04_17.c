#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// test input 1: 1 12 123 1.1 12.12 123.123
	// test input 2: 1 123 123.123 123.123 12.123 1.123
	float num1, num2, num3, num4, num5, num6;

	printf("Enter 6 real numbers: ");
	scanf("%f%f%f%f%f%f%*c", &num1, &num2, &num3, &num4, &num5, &num6);
	printf("\n");

	printf("---------------------------------\n");
	printf("| %7.3f\t| %7.3f\t|\n", num1, num2);
	printf("| %7.3f\t| %7.3f\t|\n", num3, num4);
	printf("| %7.3f\t| %7.3f\t|\n", num5, num6);
	printf("---------------------------------\n\n");

	return 0;
}