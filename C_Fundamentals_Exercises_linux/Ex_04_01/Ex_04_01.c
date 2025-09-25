#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short int number; // lowest: -32 768; highest: 32 767

	printf("Please enter an integer number.\n");
	scanf("%hd", &number);
	printf("Your number was: %hd\n", number);

	return 0;
}