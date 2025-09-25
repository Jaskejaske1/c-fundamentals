#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int money;
	float money_input;

	int amount_500, amount_200, amount_100, amount_50, amount_20, amount_10, amount_5;
	int amount_2, amount_1;
	int amount_50_cent, amount_20_cent, amount_10_cent, amount_5_cent, amount_2_cent, amount_1_cent;

	printf("Geef een hoeveelheid geld in euro (ook cent): ");
	scanf("%f%*c", &money_input);

	money = money_input * 100;

	amount_500 = money / 50000;
	money %= 50000;
	amount_200 = money / 20000;
	money %= 20000;
	amount_100 = money / 10000;
	money %= 10000;
	amount_50 = money / 5000;
	money %= 5000;
	amount_20 = money / 2000;
	money %= 2000;
	amount_10 = money / 1000;
	money %= 1000;
	amount_5 = money / 500;
	money %= 500;

	amount_2 = money / 200;
	money %= 200;
	amount_1 = money / 100;
	money %= 100;

	amount_50_cent = money / 50;
	money %= 50;
	amount_20_cent = money / 20;
	money %= 20;
	amount_10_cent = money / 10;
	money %= 10;
	amount_5_cent = money / 5;
	money %= 5;
	amount_2_cent = money / 2;
	money %= 2;
	amount_1_cent = money;

	printf("%.2f euro\n\n", money_input);
	printf("= %dx 500 euro\n", amount_500);
	printf("+ %dx 200 euro\n", amount_200);
	printf("+ %dx 100 euro\n", amount_100);
	printf("+ %dx 50 euro\n", amount_50);
	printf("+ %dx 20 euro\n", amount_20);
	printf("+ %dx 10 euro\n", amount_10);
	printf("+ %dx 5 euro\n", amount_5);
	printf("+ %dx 2 euro\n", amount_2);
	printf("+ %dx 1 euro\n", amount_1);
	printf("+ %dx 50 eurocent\n", amount_50_cent);
	printf("+ %dx 20 eurocent\n", amount_20_cent);
	printf("+ %dx 10 eurocent\n", amount_10_cent);
	printf("+ %dx 5 eurocent\n", amount_5_cent);
	printf("+ %dx 2 eurocent\n", amount_2_cent);
	printf("+ %dx 1 eurocent\n", amount_1_cent);

	return 0;
}