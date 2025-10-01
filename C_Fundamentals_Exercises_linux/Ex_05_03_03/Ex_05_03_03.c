#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number, sum = 0;

	printf("Series calculator\n");
	printf("Please enter an integer number: ");

	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	for (int i = 1; i <= number; i++)
	{
		sum += i;

		if (i == number)
		{
			printf("%d\n", i);
		}
		else
		{
			printf("%d+", i);
		}
	}

	printf("sum = %d", sum);

	printf("\n\n");

	return 0;
}