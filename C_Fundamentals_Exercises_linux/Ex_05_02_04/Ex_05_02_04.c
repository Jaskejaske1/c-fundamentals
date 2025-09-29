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

	printf("%lf matches conditions: ", number);

	// condition A
	if (number >= 3 && number < 8.5)
	{
		printf("A, ");
	}
	else
	{
		printf("not A, ");
	}

	// condition B
	if (number < 3 || (number > 5.4 && number <= 7.3) || number > 13)
	{
		printf("B, ");
	}
	else
	{
		printf("not B, ");
	}

	// condition C
	if (number != 3 && number < 9.75)
	{
		printf("C\n\n");
	}
	else
	{
		printf("not C\n\n");
	}

	return 0;
}