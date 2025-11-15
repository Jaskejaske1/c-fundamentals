/*
Example:


Please enter the temperatures for a full week:
Mon: day temp: 5
Mon: night temp: -1.5

Tue: day temp: 5.5
Tue: night temp: -0.5

Wed: day temp: 7
Wed: night temp: 0

Thu: day temp: 6
Thu: night temp: -1

Fri: day temp: 7.5
Fri: night temp: 0

Sat: day temp: 8
Sat: night temp: 1

Sun: day temp: 8.5
Sun: night temp: 1.5

		 Mon     Tue     Wed     Thu     Fri     Sat     Sun
Day      5.0     5.5     7.0     6.0     7.5     8.0     8.5
Night   -1.5    -0.5     0.0    -1.0     0.0     1.0     1.5

Min:    Night:  Mon = -1.5
		Day:    Mon =  5.0
Max:    Night:  Sun =  1.5
		Day:    Sun =  8.5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAY_CHAR_LEN 4 // + 1 for NULL byte
#define WEEK_LEN 7
#define DAY_INDEX 0
#define NIGHT_INDEX 1

void Read(float temperatures[2][WEEK_LEN], char dayNames[WEEK_LEN][DAY_CHAR_LEN]);

void Calculate(float temperatures[2][WEEK_LEN], int* p_minNightIndex, int* p_minDayIndex, int* p_maxNightIndex, int* p_maxDayIndex);

void Print(float temperatures[2][WEEK_LEN], int* p_minNightIndex, int* p_minDayIndex, int* p_maxNightIndex, int* p_maxDayIndex, char dayNames[WEEK_LEN][DAY_CHAR_LEN]);

int main(void)
{
	char dayNames[WEEK_LEN][DAY_CHAR_LEN] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
	float temperatures[2][WEEK_LEN];
	int minNightIndex, minDayIndex, maxNightIndex, maxDayIndex;

	Read(temperatures, dayNames);
	Calculate(temperatures, &minNightIndex, &minDayIndex, &maxNightIndex, &maxDayIndex);
	Print(temperatures, &minNightIndex, &minDayIndex, &maxNightIndex, &maxDayIndex, dayNames);

	return 0;
}

void Read(float temperatures[2][WEEK_LEN], char dayNames[WEEK_LEN][DAY_CHAR_LEN])
{
	printf("Please enter the temperatures for a full week:\n");
	for (int i = 0; i < WEEK_LEN; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%s: ", dayNames[i]);
			switch (j)
			{
			case 0:
				printf("day temp: ");
				break;
			case 1:
				printf("night temp: ");
				break;
			}
			(void)scanf("%f%*c", &temperatures[j][i]);
		}
		printf("\n");
	}
}

void Calculate(float temperatures[2][WEEK_LEN], int* p_minNightIndex, int* p_minDayIndex, int* p_maxNightIndex, int* p_maxDayIndex)
{
	float min, max;

	// min day (temperatures: row 0)
	min = ((float)(1e+300));
	for (int i = 0; i < WEEK_LEN; i++)
	{
		if (temperatures[DAY_INDEX][i] < min)
		{
			min = temperatures[DAY_INDEX][i];
			*p_minDayIndex = i;
		}
	}

	// min night (temperatures: row 1)
	min = ((float)(1e+300));
	for (int i = 0; i < WEEK_LEN; i++)
	{
		if (temperatures[NIGHT_INDEX][i] < min)
		{
			min = temperatures[NIGHT_INDEX][i];
			*p_minNightIndex = i;
		}
	}

	// max day (temperatures: row 0)
	max = -((float)(1e+300));
	for (int i = 0; i < WEEK_LEN; i++)
	{
		if (temperatures[DAY_INDEX][i] > max)
		{
			max = temperatures[DAY_INDEX][i];
			*p_maxDayIndex = i;
		}
	}

	// max night (temperatures: row 1)
	max = -((float)(1e+300));
	for (int i = 0; i < WEEK_LEN; i++)
	{
		if (temperatures[NIGHT_INDEX][i] > max)
		{
			max = temperatures[NIGHT_INDEX][i];
			*p_maxNightIndex = i;
		}
	}
}

void Print(float temperatures[2][WEEK_LEN], int* p_minNightIndex, int* p_minDayIndex, int* p_maxNightIndex, int* p_maxDayIndex, char dayNames[WEEK_LEN][DAY_CHAR_LEN])
{
	// print header
	for (int i = 0; i < WEEK_LEN; i++)
	{
		printf("\t%4s", dayNames[i]);
	}

	// day temperatures
	printf("\nDay\t");

	for (int i = 0; i < WEEK_LEN; i++)
	{
		printf("%4.1f\t", temperatures[DAY_INDEX][i]);
	}

	// night temperatures
	printf("\nNight\t");

	for (int i = 0; i < WEEK_LEN; i++)
	{
		printf("%4.1f\t", temperatures[NIGHT_INDEX][i]);
	}

	printf("\n\n");

	printf("Min:\tNight:\t%s = %4.1f\n", dayNames[*p_minNightIndex], temperatures[NIGHT_INDEX][*p_minNightIndex]);
	printf("\tDay:\t%s = %4.1f\n", dayNames[*p_minDayIndex], temperatures[DAY_INDEX][*p_minDayIndex]);
	printf("Max:\tNight:\t%s = %4.1f\n", dayNames[*p_maxNightIndex], temperatures[NIGHT_INDEX][*p_maxNightIndex]);
	printf("\tDay:\t%s = %4.1f\n", dayNames[*p_maxDayIndex], temperatures[DAY_INDEX][*p_maxDayIndex]);
}
