#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double number;

	printf("Please enter a real number: ");
	if (scanf("%lf%*c", &number) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (number >= 5 && number < 10)
	{
		printf("The number %lf lies in [5,10[.\n\n", number);
	}
	else
	{
		printf("The number %lf does not lie in [5,10[.\n\n", number);
	}

	return 0;
}