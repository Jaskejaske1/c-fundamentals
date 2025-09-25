#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int getal;
	int som = 0;

	printf("Geef het eerste geheel getal: ");
	scanf("%d%*c", &getal);
	som += getal;

	printf("Geef het tweede geheel getal: ");
	scanf("%d%*c", &getal);
	som += getal;

	printf("Geef het derde geheel getal: ");
	scanf("%d%*c", &getal);
	som += getal;

	printf("Geef het vierde geheel getal: ");
	scanf("%d%*c", &getal);
	som += getal;

	printf("Geef het vijfde geheel getal: ");
	scanf("%d%*c", &getal);
	som += getal;

	printf("Het gemiddelde is: %.2f\n\n", (float)som / 5);

	return 0;
}