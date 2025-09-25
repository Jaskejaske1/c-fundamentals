#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int hours, minutes;
	float seconds;

	printf("Enter hours: ");
	scanf("%d%*c", &hours);

	printf("Enter minutes: ");
	scanf("%d%*c", &minutes);

	printf("Enter seconds: ");
	scanf("%f%*c", &seconds);

	printf("The entered time is %d hours %d minutes and %f seconds\n\n", hours, minutes, seconds);

	return 0;
}