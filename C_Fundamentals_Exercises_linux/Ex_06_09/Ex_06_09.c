#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int readnumber(int lower_boundary, int upper_boundary);

int main(void)
{
	int number;
	number = readnumber(-10, 35);
	printf("The number read is %d.\n", number);
	return 0;
}

int readnumber(int lower_boundary, int upper_boundary)
{
	int number;
	do
	{
		printf("Please enter a number in the interval [%d - %d]: ", lower_boundary, upper_boundary);
		if (scanf("%d%*c", &number) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	} while (number < lower_boundary || number > upper_boundary);

	return number;
}