#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	unsigned long long factorial = 1;

	printf("Enter a natural number: ");

	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (number < 0)
	{
		printf("\nThe number must be natural, which means not negative nor floating point.\n");
		return 1;
	}

	if (number == 0)
	{
		printf("\n0! = 1\n");
		return 0;
	}

	printf("\n%d! = ", number);
	for (int i = number; i > 0; i--)
	{
		printf("%d", i);
		if (i > 1)
		{
			printf(" x ");
		}
		factorial *= i;
	}

	printf(" = %llu\n", factorial);

	return 0;
}