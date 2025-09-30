#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double num1, num2;
	char operand;

	printf("Please enter an expression without spaces in the format (num1 operand num2).\n");
	printf("The operands are : +, -, * or /\n");
	printf("Expression: ");

	if (scanf("%lf%c%lf%*c", &num1, &operand, &num2) != 3)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	switch (operand)
	{
	case '+':
		printf("%lf + %lf = %lf", num1, num2, num1 + num2);
		break;
	case '-':
		printf("%lf - %lf = %lf", num1, num2, num1 - num2);
		break;
	case '*':
		printf("%lf * %lf = %lf", num1, num2, num1 * num2);
		break;
	case '/':
		printf("%lf / %lf = %lf", num1, num2, num1 / num2);
		break;
	default:
		printf("Invalid operator.\n\n");
		return 1;
	}

	printf("\n\n");

	return 0;
}