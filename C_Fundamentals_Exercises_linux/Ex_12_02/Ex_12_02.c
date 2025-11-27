// next day program
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef enum t_month { Jan = 1, Feb = 2, Mar = 3,
Apr = 4, May = 5, Jun = 6,
Jul = 7, Aug = 8, Sep = 9,
Oct = 10, Nov = 11, Dec = 12} Month_t;

void read(int* p_day, Month_t* p_month);
void calcNextDay(int day, Month_t month, int* p_nextDay, Month_t* p_nextMonth);
void printDay(int day, Month_t month);

int main(void)
{
	int day, nextDay;
	Month_t month, nextMonth;

	read(&day, &month);

	printf("The current day is: ");
	printDay(day, month);
	printf("\n");

	calcNextDay(day, month, &nextDay, &nextMonth);

	printf("Then next day is: ");
	printDay(nextDay, nextMonth);
	printf("\n");

	return 0;
}

void read(int* p_day, Month_t* p_month)
{
	int monthTemp;
	printf("Enter the current day and month (as integers): ");
	scanf("%d%d%*c", p_day, &monthTemp);

	*p_month = (Month_t)(monthTemp);
}

void calcNextDay(int day, Month_t month, int* p_nextDay, Month_t* p_nextMonth)
{
	// assume the day is not part of leap year => feb: last day = 28
	int daysPerMonth;

	switch (month)
	{
	case Feb:
		daysPerMonth = 28;
		break;
	case Jan:
	case Mar:
	case May:
	case Jul:
	case Aug:
	case Oct:
	case Dec:
		daysPerMonth = 31;
		break;
	case Apr:
	case Jun:
	case Sep:
	case Nov:
		daysPerMonth = 30;
		break;
	default:
		daysPerMonth = 0;
		break;
	}

	if (day < daysPerMonth)
	{
		*p_nextDay = day + 1;
		*p_nextMonth = month;
	}
	else
	{
		*p_nextDay = 1;

		if (month == Dec)
		{
			*p_nextMonth = Jan;
		}
		else
		{
			*p_nextMonth = (Month_t)(month + 1);
		}
	}
}

void printDay(int day, Month_t month)
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
		monthName = "Unknown month";
		break;
	}

	printf("%s %d", monthName, day);
}
