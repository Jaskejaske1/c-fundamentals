#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAYS 7 // whole week = 7 days

/*
Write a program that reads the temperatures of a whole week into 1
array ‘temperature[]’ and prints the mean temperature for that week.
Change this exercise such that all days
with a temperature warmer than 10°C are printed.
*/

double temperature[DAYS], currentTemperature;

int main(void)
{
	for (int i = 0; i < DAYS; i++)
	{
		printf("Enter the temperature for day %d: ", i + 1);
		if (scanf("%lf%*c", &currentTemperature) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
		temperature[i] = currentTemperature;
	}

	printf("\nAll days with a temperature > 10 C:\n");
	for (int i = 0; i < DAYS; i++)
	{
		if (temperature[i] > 10)
		{
			printf("day %d\n", i + 1);
		}
	}

	printf("\n");

	return 0;
}