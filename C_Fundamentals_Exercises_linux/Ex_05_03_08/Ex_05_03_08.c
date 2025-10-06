#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float sum = 0;
	float current;

	printf("Mean of 10 numbers\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Number %d: ", i + 1);
		if (scanf("%f%*c", &current) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
		sum += current;
	}

	printf("The mean of those numbers is: %f\n", sum / 10);

	return 0;
}