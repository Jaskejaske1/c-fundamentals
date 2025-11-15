#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float eenDerde(float x);
float eenVijfde(float x);

int main(void)
{
	float(*pf)(float);
	pf = eenDerde;
	printf("Het resultaat van de functie 1/3 is: %f\n", (*pf)(15.0));

	pf = eenVijfde;
	printf("Het resultaat van de functie 1/5 is: %f\n", (*pf)(15.0)); // zelfde functieoproep, andere functie wordt opgeroepen aan de hand van functiepointer

	return 0;
}

float eenDerde(float x)
{
	return x / 3;
}

float eenVijfde(float x)
{
	return x / 5;
}