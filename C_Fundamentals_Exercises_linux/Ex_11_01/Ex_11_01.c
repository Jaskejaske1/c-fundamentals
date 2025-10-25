#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readValues(double*, double*, double*);

int main(void)
{
	double value1, value2, value3;
	readValues(&value1, &value2, &value3); // in one function call!
	printf("The three values are: %.3lf, %.3lf and %.3lf\n\n", value1, value2, value3);
	return 0;
}

void readValues(double *pValue1, double *pValue2, double *pValue3)
{
	printf("Enter 3 values: ");
	if (scanf("%lf%lf%lf%*c", pValue1, pValue2, pValue3) != 3)
	{
		printf("Invalid input.\n");
		exit(EXIT_FAILURE);
	}
}