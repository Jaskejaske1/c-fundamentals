#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double number;
	printf("Please enter a number in the interval [-2, 4.5[: ");

	if (scanf("%lf%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	while (!(number >= 2 && number < 4.5))
	{
		printf("\n%lf is outside the interval. Please try again\n", number);
		printf("Please enter a number in the interval [-2, 4.5[: ");

		if (scanf("%lf%*c", &number) != 1)
		{
			printf("\nInvalid input.\n\n");
			return 1;
		}
	}
	printf("\nThe number %lf is valid!\n\n", number);

	return 0;
}