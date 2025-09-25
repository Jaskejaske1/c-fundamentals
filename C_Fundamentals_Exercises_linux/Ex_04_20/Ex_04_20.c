#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	int honderdtallen, tientallen, eenheden;

	printf("Enter an integer number with 3 digits: ");
	scanf("%d%*c", &number);

	honderdtallen = number / 100;
	tientallen = number / 10 % 10;
	eenheden = number % 10;

	printf("The number backwards is: %d%d%d\n", eenheden, tientallen, honderdtallen);
	return 0;
}