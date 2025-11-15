#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calcSplit(int moneyInput, int *p_hundreds, int *p_fifties, int *p_twenties, int *p_fives, int *p_ones);
void printSplit(int moneyInput, int* p_hundreds, int* p_fifties, int* p_twenties, int* p_fives, int* p_ones);


int main(void)
{
	int moneyInput, hundreds, fifties, twenties, fives, ones;

	printf("Enter an amount of money below 200: ");
	scanf("%d", &moneyInput);

	calcSplit(moneyInput, &hundreds, &fifties, &twenties, &fives, &ones);
	printSplit(moneyInput, &hundreds, &fifties, &twenties, &fives, &ones);

	return 0;
}

void calcSplit(int moneyInput, int* p_hundreds, int* p_fifties, int* p_twenties, int* p_fives, int* p_ones)
{
	*p_hundreds = moneyInput / 100;
	moneyInput %= 100;

	*p_fifties = moneyInput / 50;
	moneyInput %= 50;

	*p_twenties = moneyInput / 20;
	moneyInput %= 20;

	*p_fives = moneyInput / 5;
	moneyInput %= 5;

	*p_ones = moneyInput / 1;
	moneyInput %= 1;
}

void printSplit(int moneyInput, int* p_hundreds, int* p_fifties, int* p_twenties, int* p_fives, int* p_ones)
{
	printf("%d euro can be obtained with:\n", moneyInput);
	printf("\t%2d   hundred\n", *p_hundreds);
	printf("\t%2d   fifty\n", *p_fifties);
	printf("\t%2d   twenty\n", *p_twenties);
	printf("\t%2d   five\n", *p_fives);
	printf("\t%2d   one\n", *p_ones);
}
