#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int currentDay, currentMonth, currentYear;
	int birthDay, birthMonth, birthYear;
	int ageYear, ageMonth;

	printf("Enter the current date (D M YYYY): ");
	if (scanf("%d%*c%d%*c%d%*c", &currentDay, &currentMonth, &currentYear) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter the your birth date (D M YYYY): ");
	if (scanf("%d%*c%d%*c%d%*c", &birthDay, &birthMonth, &birthYear) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	ageYear = currentYear - birthYear;
	ageMonth = currentMonth - birthMonth;

	if (currentDay < birthDay)
	{
		ageMonth -= 1;
	}

	if (ageMonth < 0)
	{
		ageYear -= 1;
		ageMonth += 12;
	}

	printf("Your age is: %d years and %d months.\n\n", ageYear, ageMonth);

	return 0;
}