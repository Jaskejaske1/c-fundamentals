#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int invoiceNumber;
	int amountOrderedProducts;
	double pricePerUnit;
	double priceTotal;

	printf("Please enter the invoice number: ");
	scanf("%d%*c", &invoiceNumber);

	printf("Please enter the number of ordered products: ");
	scanf("%d%*c", &amountOrderedProducts);

	printf("Please enter the price per unit: ");
	scanf("%lf%*c", &pricePerUnit);

	priceTotal = (double)amountOrderedProducts * pricePerUnit;

	printf("\nINVOICE\tNUMBER\tPRICE/UNIT\tTOTAL\n");
	printf("%-8d%-8d%-16.3lf%-16.3lf\n\n", invoiceNumber, amountOrderedProducts, pricePerUnit, priceTotal);

	return 0;
}