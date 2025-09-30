#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int startHours, startMinutes, startSeconds;
	int endHours, endMinutes, endSeconds;
	int diffHours, diffMinutes, diffSeconds;

	printf("Please enter the start time (hh mm ss): ");
	if (scanf("%d%*c%d%*c%d%*c", &startHours, &startMinutes, &startSeconds) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Please enter the end time (hh mm ss): ");
	if (scanf("%d%*c%d%*c%d%*c", &endHours, &endMinutes, &endSeconds) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	diffHours = endHours - startHours;
	diffMinutes = endMinutes - startMinutes;
	diffSeconds = endSeconds - startSeconds;

	if (diffSeconds < 0)
	{
		diffMinutes--;
		diffSeconds += 60; // diffSeconds = 60 - abs(diffSeconds);
	}
	
	if (diffMinutes < 0)
	{
		diffHours--;
		diffMinutes += 60;
	}

	if (diffHours < 0)
	{
		diffHours += 24;
	}

	printf("Time difference: %d %d %d\n\n", diffHours, diffMinutes, diffSeconds);

	return 0;
}