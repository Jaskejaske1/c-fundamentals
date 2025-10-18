#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAYS 7 // whole week = 7 days

/*
Write a program that reads the temperatures of a whole week into 1
array ‘temperature[]’ and prints the mean temperature for that week.

Implement above exercise using 2 functions. Make a function to read the
temperatures and a separate function to calculate the mean
temperature. Printing the mean must be done in the main program.
*/

double temperature[DAYS], mean;

void readTemperatures(double temperature[]);
double calculateMean(double temperature[]);

int main(void)
{
	readTemperatures(temperature);
	mean = calculateMean(temperature);

	printf("The mean temperature for this week is %.2lf\n\n", mean);

	return 0;
}

void readTemperatures(double temperature[])
{
	double currentTemperature;

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
}

double calculateMean(double temperature[])
{
	double sum = 0;

	for (int i = 0; i < DAYS; i++)
	{
		sum += temperature[i];
	}

	mean = sum / DAYS;
}