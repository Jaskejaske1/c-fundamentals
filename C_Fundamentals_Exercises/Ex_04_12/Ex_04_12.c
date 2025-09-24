#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int money, money_input;
	int amount_500, amount_200, amount_100, amount_50, amount_20, amount_10, amount_5;
	int amount_2, amount_1;

	printf("Geef een hoeveelheid geld in euro: ");
	scanf("%d%*c", &money_input);

	money = money_input;

	amount_500 = money / 500;
	money %= 500;
	amount_200 = money / 200;
	money %= 200;
	amount_100 = money / 100;
	money %= 100;
	amount_50 = money / 50;
	money %= 50;
	amount_20 = money / 20;
	money %= 20;
	amount_10 = money / 10;
	money %= 10;
	amount_5 = money / 5;
	money %= 5;
	amount_2 = money / 2;
	money %= 2;
	amount_1 = money;

	printf("%d euro\n", money_input);
	printf("= %dx 500 euro\n", amount_500);
	printf("+ %dx 200 euro\n", amount_200);
	printf("+ %dx 100 euro\n", amount_100);
	printf("+ %dx 50 euro\n", amount_50);
	printf("+ %dx 20 euro\n", amount_20);
	printf("+ %dx 10 euro\n", amount_10);
	printf("+ %dx 5 euro\n", amount_5);
	printf("+ %dx 2 euro\n", amount_2);
	printf("+ %dx 1 euro\n\n", amount_1);

	return 0;
}