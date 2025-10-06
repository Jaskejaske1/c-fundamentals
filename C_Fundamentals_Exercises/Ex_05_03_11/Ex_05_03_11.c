#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double base, result = 1;
	int exponent;

	printf("Enter the base: ");
	if (scanf("%lf%*c", &base) != 1)
	{
		printf("\nInvalid input.\n");
		return 1;
	}

	printf("Enter the exponent: ");
	if (scanf("%d%*c", &exponent) != 1)
	{
		printf("\nInvalid input.\n");
		return 1;
	}

	if (exponent < 0)
	{
		printf("\nThe exponent cannot be negative.\n");
		return 1;
	}

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}

	printf("\nThe result is: %lf\n", result);

	return 0;
}