#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	/*
	* Easter date calculator
	* This algorithm is valid for the Gregorian calendar and as such only after 1582.
	*/

	// declaration
	int year, a, b, c, d, e, f, g, h, i, k, l, m;
	int month, day;
	char monthName[16];

	// input
	printf("Easter day calculator\n");
	printf("This algorithm is valid for the Gregorian calendar and as such only after 1582.\n\n");
	printf("Please enter a year: ");

	if (scanf("%d", &year) != 1) // scanf return hoeveel variabelen van het verwachte type ingelezen worden
	{
		printf("Ongeldige invoer, probeer opnieuw.");
		return 1;
	}

	if (year <= 1582)
	{
		printf("Dit programma werkt enkel met jaren na 1582.");
		return 1;
	}

	/*
	* Meeus/Jones/Butcher-algoritme voor de paasdatum
	*
	* year = ingegeven jaar
	* a = jaarpositie in 19-jarige maancyclus (Metonische cyclus)
	* b = eeuw (jaar / 100)
	* c = jaar binnen de eeuw (jaar % 100)
	* d = schrikkeljaar-correctie binnen de eeuw (b / 4)
	* e = rest van die correctie (b % 4)
	* f = correctie voor de gregoriaanse schrikkelregel ((b + 8) / 25)
	* g = extra correctie voor eeuwen die geen schrikkeljaar zijn ((b - f + 1) / 3)
	* h = epacta (maanfase-correctie, leeftijd van de maan op 1 januari)
	* i = schrikkeljaar-correctie binnen de eeuw (c / 4)
	* k = rest van die correctie (c % 4)
	* l = correctie op basis van weekdagen
	* m = correctie zodat Pasen altijd na de lente-equinox valt
	*
	* month = maand van Pasen (3 = maart, 4 = april)
	* day   = dag van Pasen
	*/

	a = year % 19;
	b = year / 100;
	c = year % 100;
	d = b / 4;
	e = b % 4;
	f = (b + 8) / 25;
	g = (b - f + 1) / 3;
	h = (19 * a + b - d - g + 15) % 30;
	i = c / 4;
	k = c % 4;
	l = (32 + 2 * e + 2 * i - h - k) % 7;
	m = (a + 11 * h + 22 * l) / 451;

	month = (h + l - 7 * m + 114) / 31;
	day = ((h + l - 7 * m + 114) % 31) + 1;

	// maandnummer naar naam
	switch (month)
	{
	case 1:
		strcpy(monthName, "januari");
		break;
	case 2:
		strcpy(monthName, "februari");
		break;
	case 3:
		strcpy(monthName, "maart");
		break;
	case 4:
		strcpy(monthName, "april");
		break;
	case 5:
		strcpy(monthName, "mei");
		break;
	case 6:
		strcpy(monthName, "juni");
		break;
	case 7:
		strcpy(monthName, "juli");
		break;
	case 8:
		strcpy(monthName, "augustus");
		break;
	case 9:
		strcpy(monthName, "september");
		break;
	case 10:
		strcpy(monthName, "oktober");
		break;
	case 11:
		strcpy(monthName, "november");
		break;
	case 12:
		strcpy(monthName, "december");
		break;
	default:
		printf("Invalid month error.");
		return 1;
	}

	printf("\nPasen valt op:\n");
	printf("%02d/%02d/%d\n", day, month, year);
	printf("Zondag %02d %s %d\n\n", day, monthName, year);

	return 0;
}