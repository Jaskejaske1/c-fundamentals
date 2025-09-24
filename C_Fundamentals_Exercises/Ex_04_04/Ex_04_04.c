#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double number1, number2, sum, product;

	printf("-------~-~<Sum and Product Calculator>~-~-------\n");
	printf("================================================\n\n");

	printf("Enter the first real number: ");
	scanf("%lf%*c", &number1);

	printf("Enter the second real number: ");
	scanf("%lf%*c", &number2);

	sum = number1 + number2;
	product = number1 * number2;

	printf("The sum of the two real numbers is: %lf\n", sum);
	printf("The product of the two real numbers is: %lf\n\n", product);

	return 0;
}