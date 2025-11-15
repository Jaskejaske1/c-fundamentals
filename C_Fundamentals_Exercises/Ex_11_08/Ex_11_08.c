#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Read(int* p_base, int* p_limit);
void CalcPrint(int base, int limit, int* p_oddSum, int* p_evenSum);

int main(void)
{
	int base, limit, oddSum, evenSum;
	do
	{
		oddSum = 0;
		evenSum = 0;

		Read(&base, &limit);
		if (base != 0 && limit != 0)
		{
			CalcPrint(base, limit, &oddSum, &evenSum);
			printf("The sum of the even numbers is %d\n", evenSum);
			printf("The sum of the odd numbers is %d\n\n", oddSum);
		}
	} while (base != 0 && limit != 0);
	printf("Thanks!\n");

	return 0;
}

void Read(int* p_base, int* p_limit)
{
	printf("Enter the number you want to use for the table of multiplication: ");
	scanf("%d%*c", p_base);
	printf("Enter the limit: ");
	scanf("%d%*c", p_limit);
}

void CalcPrint(int base, int limit, int* p_oddSum, int* p_evenSum)
{
	printf("\n");
	int counter = 1, product;
	product = base * counter;

	while (product <= limit)
	{
		printf("%d\n", product);

		if (product % 2) // odd
		{
			*p_oddSum += product;
		}
		else // even
		{
			*p_evenSum += product;
		}
		counter++;
		product = base * counter;
	}
	printf("\n");
}
