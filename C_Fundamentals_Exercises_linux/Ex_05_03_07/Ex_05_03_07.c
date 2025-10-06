#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int number;
	
	do
	{
		printf("Please enter a number in the interval [-30, 30]: ");
		if (scanf("%d%*c", &number) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}

		while (number < -30 || number > 30)
		{
			printf("Please enter a number in the interval [-30, 30]: ");
			if (scanf("%d%*c", &number) != 1)
			{
				printf("Invalid input.\n\n");
				return 1;
			}
		}

		if (number > 0)
		{
			for (int i = 0; i < 30; i++)
			{
				printf(".");
			}

			printf("|");

			for (int i = 0; i < number; i++)
			{
				printf("*");
			}

			for (int i = 0; i < (30 - number); i++)
			{
				printf(".");
			}

		}
		else if (number < 0)
		{
			for (int i = 0; i < (30 - abs(number)); i++)
			{
				printf(".");
			}

			for (int i = 0; i < abs(number); i++)
			{
				printf("*");
			}

			printf("|");

			for (int i = 0; i < 30; i++)
			{
				printf(".");
			}
		}

		printf("\n");

	} while (number != 0);

	return 0;
}