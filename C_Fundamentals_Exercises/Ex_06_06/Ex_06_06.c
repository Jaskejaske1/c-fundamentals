#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double f(double);

int main(void)
{
	printf("   x\t|   y\n");
	printf("--------+--------\n");
	for (double i = -5; i <= 5; i += 0.5)
	{
		printf("%6.2lf\t|%6.2lf\n", i, f(i));
	}

	return 0;
}

double f(double x)
{
	return 2 * x * x + 2 * x - 3;
}