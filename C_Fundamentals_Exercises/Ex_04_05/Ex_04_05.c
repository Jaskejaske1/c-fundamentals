#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// declaration
	int number1, number2;
	int int_quotient, remainder;
	float real_quotient;

	// input
	printf("Enter 2 integer numbers: ");
	scanf("%d%d%*c", &number1, &number2);

	// calculation and initialization
	int_quotient = number1 / number2;
	remainder = number1 % number2;
	real_quotient = (float)number1 / number2;

	// output
	printf("integer quotient = %d\n", int_quotient);
	printf("remainder = %d\n", remainder);
	printf("quotient = %.2f\n\n", real_quotient);

	// safe exit
	return 0;
}