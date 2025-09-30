#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void lijn(int); // declaratie, met argument type

int main(void)
{
	lijn(3); // functie oproep met actueel argument 3
	lijn(16);
	lijn(-3);
	lijn(35);

	return 0;
}

void lijn(int lengte) // definitie, met argument type en naam
{
	int i;
	
	for (i = 0; i < lengte; i++)
	{
		printf("-");
	}
	printf("\n");
} // geheugen van functie wordt gewist als de functie klaar is