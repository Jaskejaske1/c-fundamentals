#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LEN 32
#define MLEN 10

typedef struct
{
	unsigned short dag;
	char maand[MLEN];
	unsigned int jaar;
} Datum;

typedef struct
{
	char naam[LEN];
	Datum gebDat;
} Persoon;

int main(void)
{
	Persoon p = { "Jan Janssens", {12, "februari", 1988} };

	printf("naam : %s\n", p.naam);
	printf("geboortedatum: %u %s %u\n", p.gebDat.dag, p.gebDat.maand, p.gebDat.jaar);

	return 0;
}
