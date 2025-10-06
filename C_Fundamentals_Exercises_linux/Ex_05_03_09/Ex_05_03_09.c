#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STOP 999

int main(void)
{
	float current;
	float sum = 0;
	int count = 0;

	printf("Advanced mean calculator (999 to stop)\n");
	do
	{
		printf("Enter a number: ");

		if (scanf("%f%*c", &current) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
		if (current != STOP)
		{
			sum += current;
			count++;
		}

	} while (current != STOP);

	if (count > 0)
	{
		printf("\nThe mean of all the numbers you entered is: %f\n", sum / count);
	}
	else
	{
		printf("\nNo numbers were entered.\n");
	}

	return 0;
}