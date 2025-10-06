#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAGEN 7

void read_temperatures(float temps[], int dagen);
float calculate_mean(float temps[], int dagen);

int main(void)
{
	float temps[DAGEN];
	float mean;

	read_temperatures(temps, DAGEN);
	mean = calculate_mean(temps, DAGEN);

	printf("\nThe mean temperature for this week is %.3f\n", mean);

	return 0;
}

void read_temperatures(float temps[], int dagen)
{
	for (int i = 0; i < dagen; i++)
	{
		printf("Enter temperature for day %d: ", i + 1);
		if (scanf("%f%*c", &temps[i]) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	}
}

float calculate_mean(float temps[], int dagen)
{
	float sum = 0;
	for (int i = 0; i < dagen; i++)
	{
		sum += temps[i];
	}
	return sum / dagen;
}