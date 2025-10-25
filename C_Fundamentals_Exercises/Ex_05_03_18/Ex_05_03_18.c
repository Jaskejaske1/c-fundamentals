#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double current, max;
	int maxCount = 0;

	printf("Enter 10 numbers.\n");

	for (int i = 0; i < 10; i++)
	{
		printf("Number %d: ", i + 1);
		(void)scanf("%lf%*c", &current);
		
		if (i == 0)
		{
			max = current;
		}

		if (current > max)
		{
			max = current;
		}

		if (current == max)
		{
			maxCount++;
		}
	}

	printf("The maximum number was %lf and it appeared %d times.\n\n", max, maxCount);

	return 0;
}
