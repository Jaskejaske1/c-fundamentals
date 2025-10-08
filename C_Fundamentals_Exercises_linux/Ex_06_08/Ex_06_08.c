#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int readnumber(void);

int main(void)
{
	int number;
	number = readnumber();
	printf("The number read is %d.\n", number);
	return 0;
}

int readnumber(void)
{
	int number;
	do
	{
		printf("Please enter a number in the interval [0 - 10]: ");
		if (scanf("%d%*c", &number) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	} while (number < 0 || number > 10);

	return number;
}