#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float number1, number2, quotient;

	printf("Enter 2 real numbers: ");
	scanf("%f%f%*c", &number1, &number2);

	quotient = number1 / number2;

	printf("the quotient is: %.20f\n\n", quotient);

	return 0;
}