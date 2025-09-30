#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double R1, R2, R_eq;
	printf("Parallel resistor calculator\n");

	printf("Enter R1: ");

	if (scanf("%lf%*c", &R1) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter R2: ");

	if (scanf("%lf%*c", &R2) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (R1 < 0 || R2 < 0)
	{
		printf("Resistance cannot be negative.\n\n");
		return 1;
	}
	else if (R1 == 0 || R2 == 0)
	{
		R_eq = 0;
	}
	else
	{
		R_eq = 1 / (1 / R1 + 1 / R2);
	}
	
	printf("The equivalent resistance R_eq = %.3lf Ohms.\n\n", R_eq);

	return 0;
}