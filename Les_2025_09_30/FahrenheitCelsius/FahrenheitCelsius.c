#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define F_START -10
#define F_STOP 100
#define F_INC 5

float fahrenheitToCelsius(int);

int main(void)
{
	int fahrenheit;

	printf("+-------------+\n");
	printf("|  F  |   C   |\n");
	printf("+-------------+\n");

	for (fahrenheit = F_START; fahrenheit <= F_STOP; fahrenheit += F_INC)
	{
		printf("|%4d | %6.2f|\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
	}
	printf("+-------------+\n\n");
	return 0;
}

float fahrenheitToCelsius(int fahrenheit)
{
	float celsius = 5 * ((float)fahrenheit - 32) / 9;
	return celsius;
}