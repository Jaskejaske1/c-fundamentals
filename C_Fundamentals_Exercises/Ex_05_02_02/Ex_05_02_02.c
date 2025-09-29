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

	if (number % 2)
	{
		printf("The number %d is uneven.\n\n", number);
	}
	else
	{
		printf("The number %d is even.\n\n", number);
	}
	return 0;
}