#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	printf("Please enter an integer number: ");
	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (number > 0)
	{
		printf("The number %d is positive.\n\n", number);
	}
	else
	{
		printf("The number %d is not positive.\n\n", number);
	}

	return 0;
}