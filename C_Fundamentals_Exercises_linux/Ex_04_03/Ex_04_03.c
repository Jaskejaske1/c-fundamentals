#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number1, number2;

	printf("Enter 2 integer numbers: ");
	scanf("%d%d%*c", &number1, &number2);
	printf("The entered numbers are %d and %d", number1, number2);
	return 0;
}