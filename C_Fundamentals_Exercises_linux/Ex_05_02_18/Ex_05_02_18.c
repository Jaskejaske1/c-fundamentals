#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, D, x1, x2;

	printf("Quadratic equation real root finder\n");
	printf("Please enter the coefficients a, b and c: ");
	if (scanf("%lf%lf%lf%*c", &a, &b, &c) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (a)
	{
		D = b * b - 4 * a * c;

		if (D < 0)
		{
			printf("No real roots");
		}
		else if (D == 0)
		{
			x1 = (-b + sqrt(D)) / 2 * a;
			printf("Double real root: %.3lf", x1);
		}
		else // D > 0
		{
			x1 = (-b - sqrt(D)) / (2 * a);
			x2 = (-b + sqrt(D)) / (2 * a);

			printf("Two real roots: %.3lf and %.3lf", x1, x2);
		}
	}
	else // linear: bx + c = 0 => x1 = - b / a
	{
		if (b)
		{
			x1 = -c / b;
			printf("One solution %.3lf", x1);
		}
		else if (!b && c)
		{
			printf("No solutions (inconsistent equation: %.3lf = 0)",  c);
		}
		else
		{
			printf("Identity 0 = 0");
		}
	}

	printf("\n\n");

	return 0;
}