#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	// general formula: (hypotenuse)^2 = (side1)^2 + (side2)^2

	double side1, side2, hypotenuse;

	printf("Please enter side 1: ");
	if (scanf("%lf%*c", &side1) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Please enter side 2: ");
	if (scanf("%lf%*c", &side2) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Please enter hypotenuse: ");
	if (scanf("%lf%*c", &hypotenuse) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (side1 < 0 || side2 < 0 || hypotenuse < 0)
	{
		printf("Negative length does not exist.\n\n");
		return 1;
	}

	if (side1 == 0)
	{
		if (hypotenuse <= side2)
		{
			printf("Invalid triangle dimensions.\n\n");
			return 1;
		}
		side1 = sqrt(hypotenuse * hypotenuse - side2 * side2);
		printf("Side 1 = %.2lf.\n", side1);
	}
	else if (side2 == 0)
	{
		if (hypotenuse <= side1)
		{
			printf("Invalid triangle dimensions.\n\n");
			return 1;
		}
		side2 = sqrt(hypotenuse * hypotenuse - side1 * side1);
		printf("Side 2 = %.2lf.\n", side2);
	}
	else if (hypotenuse == 0)
	{
		hypotenuse = sqrt(side1 * side1 + side2 * side2);
		printf("Hypotenuse = %.2lf.\n", hypotenuse);
	}
	else
	{
		printf("Leave one side as zero to compute it.\n\n");
		return 1;
	}

	return 0;
}