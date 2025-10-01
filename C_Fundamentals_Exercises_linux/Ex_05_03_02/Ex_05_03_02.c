#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number, stop;

	printf("Multiplication tables\n");
	printf("Please enter an integer number: ");

	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Please enter the stop value: ");

	if (scanf("%d%*c", &stop) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (stop < 1)
	{
		printf("Stop value cannot be lower than 1.");
		return 1;
	}

	printf("The table of multiplication of %d is:\n", number);

	for (int i = 1; i <= stop; i++)
	{
		printf("%d x %d = %d\n", i, number, i * number);
	}

	printf("\n");

	return 0;
}