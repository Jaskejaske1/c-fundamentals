#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef enum t_month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month_t;

Month_t lastMonth(Month_t current);
void printMonth(Month_t month);

int main(void)
{
	printf("Current Month | Previous Month\n");
	printf("------------------------------\n");

	Month_t current, previous;

	for (current = Jan; current <= Dec; current++)
	{
		previous = lastMonth(current);

		printMonth(current);
		printf(" | ");
		printMonth(previous);
		printf("\n");
	}

	return 0;
}

Month_t lastMonth(Month_t current)
{
	if (current == Jan)
	{
		return Dec;
	}
	else
	{
		return (Month_t)(current - 1);
	}
}

void printMonth(Month_t month)
{
	const char* monthName;
	switch (month)
	{
	case Jan:
		monthName = "January";
		break;
	case Feb:
		monthName = "February";
		break;
	case Mar:
		monthName = "March";
		break;
	case Apr:
		monthName = "April";
		break;
	case May:
		monthName = "May";
		break;
	case Jun:
		monthName = "June";
		break;
	case Jul:
		monthName = "July";
		break;
	case Aug:
		monthName = "August";
		break;
	case Sep:
		monthName = "September";
		break;
	case Oct:
		monthName = "October";
		break;
	case Nov:
		monthName = "November";
		break;
	case Dec:
		monthName = "December";
		break;
	default:
		monthName = "Unknown";
		break;
	}
	printf("%-13s", monthName);
}