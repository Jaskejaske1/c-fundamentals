#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double number;

	printf("Please enter a real number: ");
	if (scanf("%lf%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (number > 0)
	{
		printf("The number %lf is positive.\n\n", number);
	}
	else if (number < 0)
	{
		printf("The number %lf is negative.\n\n", number);
	}
	else
	{
		printf("The number %lf is zero.\n\n", number);
	}

	return 0;
}