#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(long long int number1, long long int number2);

int main(void)
{
	long long number1, number2, number3, result;
	printf("Enter three integer numbers: ");
	if (scanf("%lld%lld%lld%*c", &number1, &number2, &number3) != 3)
	{
		printf("Invalid input.\n\n");
	}

	result = gcd(number1, gcd(number2, number3));

	printf("The gcd of these three numbers is: %lld.\n\n", result);

	return 0;
}

int gcd(long long int number1,long long int number2)
{
	long long int temp;
	while (number2 != 0)
	{
		temp = number2;
		number2 = number1 % number2;
		number1 = temp;
	}
	return number1;
}