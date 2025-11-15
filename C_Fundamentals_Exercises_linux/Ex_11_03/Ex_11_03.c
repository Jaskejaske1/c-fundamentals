/*
Write a program that converts a number of seconds into a number of
hours, minutes and seconds. Reading the number of seconds and
printing the result is done in the main function. The calculations are
done in a separate function. No arrays are to be used!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void convert(int inputSeconds, int* hours, int* minutes, int* seconds);

int main(void)
{
	int inputSeconds, hours, minutes, seconds;

	printf("Enter a time in seconds: ");
	(void)scanf("%d%*c", &inputSeconds);
	convert(inputSeconds, &hours, &minutes, &seconds);
	printf("The entered time of %d seconds equals %d hours, %d minutes and %d seconds.\n", inputSeconds, hours, minutes, seconds);
	return 0;
}

void convert(int inputSeconds, int* p_hours, int* p_minutes, int* p_seconds)
{
	*p_hours = inputSeconds / 3600;
	*p_minutes = (inputSeconds - (3600 * *p_hours)) / 60;
	*p_seconds = (inputSeconds - (3600 * *p_hours) - (*p_minutes * 60));
}
