#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float consumption, priceExVat, priceTotal;
	const float vat = 0.21;

	printf("Please enter your gas consumption (m^3): ");

	if (scanf("%f%*c", &consumption) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (consumption < 0)
	{
		printf("Consumption cannot be negative.\n");
		return 1;
	}
	else if (consumption <= 1)
	{
		priceExVat = 20;
	}
	else
	{
		// 20 for the first m^3, 3.5/m^3 for the rest (= total - 1)
		priceExVat = 20 + 3.5 * (consumption - 1);
	}

	priceTotal = priceExVat * (1 + vat);

	printf("\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| CONSUMPTION\tPRICE EX VAT\tTAX AMOUNT\tTOTAL PRICE |\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| %.3f m^3\t%.2f\t\t%.1f %%\t\t%-11.2f |\n", consumption, priceExVat, vat * 100, priceTotal);
	printf("+-----------------------------------------------------------+\n");

	return 0;
}