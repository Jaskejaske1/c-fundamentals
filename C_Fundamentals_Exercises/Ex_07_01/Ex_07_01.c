#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAYS 7 // whole week = 7 days

/*
Write a program that reads the temperatures of a whole week into 1
array ‘temperature[]’ and prints the mean temperature for that week.
*/

double temperature[DAYS], currentTemperature, sum = 0, mean;

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

	for (int i = 0; i < DAYS; i++)
	{
		sum += temperature[i];
	}

	mean = sum / DAYS;

	printf("The mean temperature for this week is %.2lf\n\n", mean);

	return 0;
}