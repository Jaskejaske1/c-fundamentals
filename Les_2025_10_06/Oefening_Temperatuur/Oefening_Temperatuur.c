#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAGEN 7

int main(void)
{
	float temps[DAGEN];
	float sum = 0, mean;

	for (int i = 0; i < DAGEN; i++)
	{
		printf("Enter temperature for day %d: ", i + 1);
		if (scanf("%f%*c", &temps[i]) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	}

	for (int i = 0; i < DAGEN; i++)
	{
		sum += temps[i];
	}
	mean = sum / DAGEN;

	printf("\nThe mean temperature for this week is %.3f\n", mean);

	return 0;
}