#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} Months;

void printMonth(Months);

int main(void)
{
	printf("De maanden van het jaar zijn:\n");
	printf("nr.\t| naam\n");
	printf("-----------------------------\n");

	for (Months i = jan; i <= dec; i++)
	{
		printf("%d\t|", i);
		printMonth(i);
		printf("\n");
	}
	return 0;
}

void printMonth(Months m)
{
	switch (m)
	{
	case jan:
		printf("januari");
		break;
	case feb:
		printf("februari");
		break;
	case mar:
		printf("maart");
		break;
	case may:
		printf("mei");
		break;
	case jun:
		printf("juni");
		break;
	case jul:
		printf("juli");
		break;
	case aug:
		printf("augustus");
		break;
	case sep:
		printf("september");
		break;
	case oct:
		printf("oktober");
		break;
	case nov:
		printf("november");
		break;
	case dec:
		printf("december");
		break;
	default:
		printf("none");
		break;
	}
}