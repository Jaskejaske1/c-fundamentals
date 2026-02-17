#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	int dag;
	int maand;
	int jaar;
} Geboortedatum;


typedef struct
{
	char naam[MAX_LEN];
	Geboortedatum geboortedatum;
	char gemeente[MAX_LEN];
} Persoon;


int bereken(int huidige_dag, int huidige_maand, int huidig_jaar, int geboorte_dag, int geboorte_maand, int geboorte_jaar);
int lees(FILE* fp, Persoon* personen, int dag, int maand, int jaar, int leeftijdsgrens, int max_aantal);
int kies(void);
void printen(int keuze, Persoon* personen, int aantal_gevonden_personen, int dag, int maand, int jaar);
void print_binary(short input);


int main(int argc, char * argv[])
{
	char filenaam[MAX_LEN];
	int input_dag, input_maand, input_jaar, input_leeftijdsgrens, input_max_aantal, aantal_gevonden_personen, keuze;
	FILE* fp;
	Persoon* personen;

	// Oproep: programma.exe filenaam dag maand jaar leeftijdsgrens max_aantal

	if (argc != 7)
	{
		printf("Geef de correcte argumenten in:\nprogramma.exe <filenaam><dag><maand><jaar><leeftijdsgrens><max aantal>\n");
		exit(EXIT_FAILURE);
	}

	strcpy(filenaam, argv[1]);
	input_dag = atoi(argv[2]);
	input_maand = atoi(argv[3]);
	input_jaar = atoi(argv[4]);
	input_leeftijdsgrens = atoi(argv[5]);
	input_max_aantal = atoi(argv[6]);

	fp = fopen(filenaam, "r");
	if (fp == NULL)
	{
		printf("Het opgegeven bestand %s kan niet geopend worden.\n", filenaam);
		exit(EXIT_FAILURE);
	}

	// dynamische array van structs
	personen = (Persoon *) malloc(input_max_aantal * sizeof(Persoon));

	if (personen == NULL)
	{
		printf("Geheugenallocatie mislukt!\n");
		exit(EXIT_FAILURE);
	}

	// functiecalls

	aantal_gevonden_personen = lees(fp, personen, input_dag, input_maand, input_jaar, input_leeftijdsgrens, input_max_aantal);
	fclose(fp);

	if (aantal_gevonden_personen == 0)
	{
		printf("Geen personen gevonden die ouder zijn dan %d jaar.", input_leeftijdsgrens);
		return 0;
	}

	keuze = kies(); // 1 = jongste, 2 = gemeente

	printen(keuze, personen, aantal_gevonden_personen, input_dag, input_maand, input_jaar);

	free(personen);
	personen = NULL;
	return 0;
}


int bereken(int huidige_dag,  int huidige_maand,  int huidige_jaar,
	        int geboorte_dag, int geboorte_maand, int geboorte_jaar)
{
	int leeftijd = huidige_jaar - geboorte_jaar;

	if (huidige_maand < geboorte_maand || (huidige_maand == geboorte_maand && huidige_dag < geboorte_dag))
	{
		leeftijd--;
	}

	return leeftijd;
}


int lees(FILE* fp, Persoon* personen, int dag, int maand, int jaar, int leeftijdsgrens, int max_aantal)
{
	Persoon temp;

	int aantal_gevonden_personen = 0;

	while (fgets(temp.naam, MAX_LEN, fp) != NULL && aantal_gevonden_personen < max_aantal)
	{
		(void)fscanf(fp, "%d%d%d%*c", &temp.geboortedatum.dag, &temp.geboortedatum.maand, &temp.geboortedatum.jaar);
		fgets(temp.gemeente, MAX_LEN, fp);
		
		temp.naam[strcspn(temp.naam, "\n")] = '\0';
		temp.gemeente[strcspn(temp.gemeente, "\n")] = '\0';

		if (bereken(dag, maand, jaar, temp.geboortedatum.dag, temp.geboortedatum.maand, temp.geboortedatum.jaar) >= leeftijdsgrens)
		{
			personen[aantal_gevonden_personen] = temp;
			aantal_gevonden_personen++;
		}
	}

	return aantal_gevonden_personen;
}


int kies(void) // 1 = jongste, 2 = gemeente
{
	int keuze;
	do
	{
		printf("Maak uw keuze:\n");
		printf("1\tjongste\n");
		printf("2\tin gemeente\n");
		printf("keuze: ");
		(void)scanf("%d%*c", &keuze);

		if ((keuze != 1) && (keuze != 2))
		{
			printf("Dit is geen geldige keuze!\n");
		}
	} while ((keuze != 1) && (keuze != 2));

	return keuze;
}


void printen(int keuze, Persoon* personen, int aantal_gevonden_personen, int dag, int maand, int jaar)
{
	char gemeente[MAX_LEN];
	int huidige_leeftijd, jongste_leeftijd = -1;
	Persoon huidige_persoon, jongste_persoon;

	switch (keuze) // keuze: 1 = jongste, 2 = gemeente
	{
	case 1:
		for (int i = 0; i < aantal_gevonden_personen; i++)
		{
			huidige_persoon = personen[i];
			huidige_leeftijd = bereken(dag, maand, jaar, huidige_persoon.geboortedatum.dag, huidige_persoon.geboortedatum.maand, huidige_persoon.geboortedatum.jaar);

			if (i == 0)
			{
				jongste_leeftijd = huidige_leeftijd;
				jongste_persoon = huidige_persoon;
			}

			if (huidige_leeftijd < jongste_leeftijd)
			{
				jongste_leeftijd = huidige_leeftijd;
				jongste_persoon = huidige_persoon;
			}
		}

		printf("De jongste persoon in deze leeftijdscategorie is:\n");
		printf("%s\n", jongste_persoon.naam);
		printf("%d\t%x\t", jongste_leeftijd, jongste_leeftijd);
		print_binary((short)jongste_leeftijd);
		printf("\n");

		break;
	case 2:
		printf("Van welke gemeente wil je de leeftijden kennen? ");
		fgets(gemeente, MAX_LEN, stdin);
		gemeente[strcspn(gemeente, "\n")] = '\0';

		printf("De inwoners van de gemeente %s in de gekozen leeftijdscategorie zijn:\n", gemeente);

		for (int i = 0; i < aantal_gevonden_personen; i++)
		{
			huidige_persoon = personen[i];

			if (strcmp(huidige_persoon.gemeente, gemeente) == 0) // gelijke inhoud
			{
				huidige_leeftijd = bereken(dag, maand, jaar, huidige_persoon.geboortedatum.dag, huidige_persoon.geboortedatum.maand, huidige_persoon.geboortedatum.jaar);
				printf("%s\n", huidige_persoon.naam);
				printf("%d\n\n", huidige_leeftijd);
			}
		}

		break;
	default:
		printf("De keuze %d bestaat niet.\n", keuze);
		exit(EXIT_FAILURE);
		break;
	}
}


void print_binary(short input)
{
	short bit;
	for (short i = 15; i >= 0; i--)
	{
		bit = input >> i & 1;
		printf("%hd", bit);
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
}