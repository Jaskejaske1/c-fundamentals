#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAYS 7 // whole week = 7 days

/*
Write a program that reads the temperatures of a whole week into 1
array ‘temperature[]’ and prints the mean temperature for that week.
Change this exercise such that all days
with a temperature warmer than 10°C are printed.

Repeat the above exercise but this time, use 3 separate functions to read
the temperatures (“ReadTemp”), to determine which days are warmer
than 10°C (“Calculate”) and to print the days found (“PrintDays”).
Extra: ask the user to enter a temperature limit.
*/

double temperature[DAYS], days[DAYS], temperatureLimit;

double readTemperatureLimit(void);
void readTemp(double temperature[]);
void calculateWarmerDays(double temperature[], double days[], double temperatureLimit);
void printDays(double days[]);

int main(void)
{
	temperatureLimit = readTemperatureLimit();

	readTemp(temperature);
	calculateWarmerDays(temperature, days, temperatureLimit);

	printf("\nAll days with a temperature > 10 C:\n");
	printDays(days);

	printf("\n");

	return 0;
}

void readTemp(double temperature[])
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

void calculateWarmerDays(double temperature[], double days[], double temperatureLimit)
{
	for (int i = 0; i < DAYS; i++)
	{
		if (temperature[i] > temperatureLimit)
		{
			days[i] = 1;
		}
		else
		{
			days[i] = 0;
		}
	}
}

void printDays(double days[])
{
	for (int i = 0; i < DAYS; i++)
	{
		if (days[i] == 1)
		{
			printf("day %d\n", i + 1);
		}
	}
}

double readTemperatureLimit(void)
{
	double temperatureLimit;

	printf("Please enter the temperature limit: ");

	if (scanf("%lf%*c", &temperatureLimit) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	return temperatureLimit;
}