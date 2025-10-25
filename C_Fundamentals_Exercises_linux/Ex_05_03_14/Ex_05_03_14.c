#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double current, min = 0, max = 0;
	int counter, minPlace, maxPlace;

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
			minPlace = counter + 1;
		}
		if (current > max)
		{
			max = current;
			maxPlace = counter + 1;
		}
	}

	printf("Min: %lf at place %d\n", min, minPlace);
	printf("Max: %lf at place %d\n", max, maxPlace);

	return 0;
}