#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int seconds_input;
	int seconds, minutes, hours, days;

	printf("Please enter a number of seconds: ");
	scanf("%d%*c", &seconds_input);

	minutes = seconds_input / 60;
	seconds = seconds_input % 60;

	hours = minutes / 60;
	minutes = minutes % 60;

	days = hours / 24;
	hours = hours % 24;

	/* gemakkelijke versie
	printf("%d sec = %d day(s), %d hour(s), %d minute(s) and %d second(s).", seconds_input, days, hours, minutes, seconds);
	*/

	if (seconds_input == 1) // Ik weet dat ik de '== 1" kan weglaten, maar doe het voor de duidelijkheid.
	{
		printf("%d second = ", seconds_input);
	}
	else
	{
		printf("%d seconds = ", seconds_input);
	}

	if (days == 1)
	{
		printf("%d day, ", days);
	}
	else
	{
		printf("%d days, ", days);
	}

	if (hours == 1)
	{
		printf("%d hour, ", hours);
	}
	else
	{
		printf("%d hours, ", hours);
	}


	if (minutes == 1)
	{
		printf("%d minute and ", minutes);
	}
	else
	{
		printf("%d minutes and ", minutes);
	}

	if (seconds == 1)
	{
		printf("%d second.", seconds);
	}
	else
	{
		printf("%d seconds.", seconds);
	}

	printf("\n\n");
	return 0;
}