#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int input1, input2, number1, number2;

	printf("Enter 2 positive integers: ");
	(void)scanf("%d%d%*c", &input1, &input2);
	printf("\n");

	number1 = input1;
	number2 = input2;

	printf("%d\t%d\n", number1, number2);

	while (number1 != number2)
	{
		if (number1 > number2)
		{
			number1 = number1 - number2;
		}
		else if (number2 > number1)
		{
			number2 = number2 - number1;
		}

		printf("%d\t%d\n", number1, number2);
	}

	printf("\nThe gcd of %d and %d equals %d.\n\n", input1, input2, number1);

	return 0;
}