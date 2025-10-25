#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readNumbers(double*, double*);
double calculateSum(double, double);
void printSum(double);

int main(void)
{
	double number1, number2, sum;
	readNumbers(&number1, &number2);
	sum = calculateSum(number1, number2);
	printSum(sum);
	return 0;
}

void readNumbers(double *pGetal1, double *pGetal2)
{
	printf("Enter two numbers: ");
	(void)scanf("%lf%lf%*c", pGetal1, pGetal2);
}

double calculateSum(double getal1, double getal2)
{
	return getal1 + getal2;
}

void printSum(double sum)
{
	printf("The sum is %lf.\n", sum);
}