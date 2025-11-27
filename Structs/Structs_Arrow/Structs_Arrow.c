#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 30

typedef struct {
	int nummer;
	char omschrijving[LEN];
	int aantal;
	float inkoopprijs;
	float verkoopprijs;
} Artikel;

void lees(Artikel*);
void druk(Artikel);

int main(void)
{
	Artikel a;

	lees(&a);
	druk(a);

	return 0;
}

void lees(Artikel* p)
{
	printf("Geef artikelnummer : ");
	scanf("%d%*c", &(p->nummer));

	printf("Geef omschrijving : ");
	gets(p->omschrijving);

	printf("Geef het aantal in stock: ");
	scanf("%d%*c", &(p->aantal));

	printf("Geef inkoopprijs : ");
	scanf("%f%*c", &(p->inkoopprijs));

	printf("Geef verkoopprijs : ");
	scanf("%f%*c", &(p->verkoopprijs));
}

void druk(Artikel z)
{
	printf("\n");
	printf("artikelnummer:\t%d\n", z.nummer);
	printf("omschrijving:\t%s\n", z.omschrijving);
	printf("aantal stock:\t%d\n", z.aantal);
	printf("inkoopprijs:\t%.2f\n", z.inkoopprijs);
	printf("verkoopprijs:\t%.2f\n", z.verkoopprijs);
}
