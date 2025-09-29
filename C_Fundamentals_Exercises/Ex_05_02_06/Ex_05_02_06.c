#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// loops are forbidden, max 2 variables
int main(void)
{
	int number, test;

	printf("Please enter the first integer: ");
	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}
	printf("Please enter the second integer: ");
	if (scanf("%d%*c", &test) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (test < number)
	{
		number = test;
	}

	printf("Please enter the third integer: ");
	if (scanf("%d%*c", &test) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (test < number)
	{
		number = test;
	}

	printf("Please enter the fourth integer: ");
	if (scanf("%d%*c", &test) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (test < number)
	{
		number = test;
	}

	printf("Please enter the fifth integer: ");
	if (scanf("%d%*c", &test) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (test < number)
	{
		number = test;
	}

	printf("The lowest number was %d.\n\n", number);

	return 0;
}