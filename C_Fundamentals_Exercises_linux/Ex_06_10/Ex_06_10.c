#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double exponentiation(double base, int exponent);

int main(void)
{
	double base, result;
	int exponent;

	printf("Exponentation\n-------------\n");

	printf("Enter a base: ");
	if (scanf("%lf%*c", &base) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter an exponent: ");
	if (scanf("%d%*c", &exponent) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	result = exponentiation(base, exponent);

	printf("The result is: %.4lf.\n\n", result);

	return 0;
}

double exponentiation(double base, int exponent)
{
	double result  = 1;

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}

	return result;
}