#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int day, month, year, weekDay, factor;

	printf("Day of the week calculator\n");
	printf("--------------------------\n");

	printf("Please enter a date (DD M YYYY): ");
	if (scanf("%d%d%d%*c", &day, &month, &year) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (day < 1 || day > 31)
	{
		printf("Invalid day.\n");
		return 1;
	}
	if (month < 1 || month > 12)
	{
		printf("Invalid month.\n");
		return 1;
	}

	if (month == 1 || month == 2) // January and february
	{
		factor = 365 * year + day + 31 * (month - 1) + ((year - 1) / 4) - ((((year - 1) / 100) + 1) * (3 / 4));
	}
	else // March till december
	{
		factor = 365 * year + day + 31 * (month - 1) - (0.4 * month + 2.3) + (year / (float)4) - (((year / (float)100) + 1) * (3 / 4));
	}

	weekDay = factor - (int)(factor / 7) * 7;

	printf("%d/%d/%d is a ", day, month, year);

	switch (weekDay)
	{
	case 0:
		printf("saturday");
		break;
	case 1:
		printf("sunday");
		break;
	case 2:
		printf("monday");
		break;
	case 3:
		printf("tuesday");
		break;
	case 4:
		printf("wednesday");
		break;
	case 5:
		printf("thursday");
		break;
	case 6:
		printf("friday");
		break;
	default:
		printf("wrong day\n\n");
		return 1;
	}

	printf(".\n\n");

	return 0;
}