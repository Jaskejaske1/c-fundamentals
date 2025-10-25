#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double readNumber(void);
double calculateSum(double, double);
void printSum(double, double, double);

int main(void)
{
	double number1, number2, sum;

	number1 = readNumber();
	number2 = readNumber();
	sum = calculateSum(number1, number2);
	printSum(number1, number2, sum);

	return 0;
}

double readNumber(void)
{
	double number;
	printf("Enter a number: ");
	if (scanf("%lf%*c", &number) != 1)
	{
		printf("Invalid input.\n");
		exit(EXIT_FAILURE);
	}
	return number;
}

double calculateSum(double number1, double number2)
{
	return number1 + number2;
}

void printSum(double number1, double number2, double sum)
{
	printf("The sum of %.2lf and %.2lf is %.2lf.\n", number1, number2, sum);
}