#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	long number; // lowest: -2 147 483 648; highest: 2 147 483 647

	printf("Please enter a long integer number.\n");
	scanf("%ld", &number);
	printf("Your number was: %ld\n", number);
	return 0;
}