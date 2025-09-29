#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int number;
	double sqrtNumber;

	printf("Square root calculator\n");
	printf("Please enter a number: ");

	if (scanf("%d%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}
	if (number < 0)
	{
		printf("Square roots of negative numbers do not exist.\n\n");
		return 1;
	}

	sqrtNumber = sqrt((double)number);
	printf("The square root of %d is %lf.\n\n", number, sqrtNumber);
	return 0;
}