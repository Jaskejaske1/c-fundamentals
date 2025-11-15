/*
Write a program to swap two numbers.
The first number is stored in the variable number1
and the second in the variable number2.
After the swap the variable number1 contains the second number
and number2 contains the first number.
Use functions: Read, Swap, Print. Do not use arrays!

Example:

Enter 2 numbers: 5 10
The value of the first variable is 5, the value of the second variable is 10.
After the swap, variable 1 contains 10 and variable 2 contains 5.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* p_number1, int* p_number2);

int main(void)
{
	int number1, number2;
	printf("Enter 2 numbers: ");
	(void)scanf("%d%d%*c", &number1, &number2);

	printf("The value of the first variable is %d, the value of the second variable %d.\n", number1, number2);
	swap(&number1, &number2);
	printf("After the swap, variable 1 contains %d and variable 2 contains %d.\n", number1, number2);

	return 0;
}

void swap(int* p_number1, int* p_number2)
{
	int temp;
	temp = *p_number1;
	*p_number1 = *p_number2;
	*p_number2 = temp;
}
