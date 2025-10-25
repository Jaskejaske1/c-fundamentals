#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define AMOUNT 2

void readNumbers(double[]);
double calculateSum(double[]);
void printSum(double[], double);

int main(void)
{
	double numbers[AMOUNT], sum;

	readNumbers(numbers);
	sum = calculateSum(numbers);
	printSum(numbers, sum);

	return 0;
}

void readNumbers(double numbers[])
{
	for (int i = 0; i < AMOUNT; i++)
	{
		printf("Enter a number: ");
		if (scanf("%lf%*c", &numbers[i]) != 1)
		{
			printf("Invalid input.\n");
			exit(EXIT_FAILURE);
		}
	}
}

double calculateSum(double numbers[])
{
	double sum = 0;
	for (int i = 0; i < AMOUNT; i++)
	{
		sum += numbers[i];
	}
	return sum;
}

void printSum(double numbers[], double sum)
{
	printf("The sum of %.2lf and %.2lf is %.2lf.\n", numbers[0], numbers[1], sum);
}