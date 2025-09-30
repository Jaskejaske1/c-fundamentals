#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// loops are forbidden
int main(void)
{
	double a, b, c;

	printf("Please enter three real numbers: ");
	if (scanf("%lf%*c%lf%*c%lf%*c", &a, &b, &c) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (a < b && b < c)
	{
		printf("%.3lf < %.3lf < %.3lf", a, b, c);
	}
	else if (a < c && c < b)
	{
		printf("%.3lf < %.3lf < %.3lf", a, c, b);
	}
	else if (b < a && a < c)
	{
		printf("%.3lf < %.3lf < %.3lf", b, a, c);
	}
	else if (b < c && c < a)
	{
		printf("%.3lf < %.3lf < %.3lf", b, c, a);
	}
	else if (c < a && a < b)
	{
		printf("%.3lf < %.3lf < %.3lf", c, a, b);
	}
	else if (c < b && b < a)
	{
		printf("%.3lf < %.3lf < %.3lf", c, b, a);
	}

	printf("\n\n");

	return 0;
}