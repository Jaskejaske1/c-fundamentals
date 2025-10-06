#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double current, min = 0, max = 0;
	int counter;

	for (counter = 0; counter < 10; counter++)
	{
		printf("Please enter a number: ");
		if (scanf("%lf%*c", &current) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}

		if (current < min)
		{
			min = current;
		}
		if (current > max)
		{
			max = current;
		}
	}

	printf("Min: %lf\n", min);
	printf("Max: %lf\n", max);

	return 0;
}