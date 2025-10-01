#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int limit, number, sum = 0;

	printf("Please enter the limit (int): ");

	if (scanf("%d%*c", &limit) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	while (sum < limit)
	{
		printf("Enter an integer number: ");
		if (scanf("%d%*c", &number) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}

		sum += number;
	}

	printf("The limit of %d is reached or exceeded.", limit);

	printf("\n\n");

	return 0;
}