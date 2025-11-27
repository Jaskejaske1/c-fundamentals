#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define N 2

#include <stdio.h>
#include <string.h>

typedef struct
{
	char voornaam[LEN];
	char achternaam[LEN];
} Person;

Person readOnePerson();
void printPeople(Person people[]);

int main(void)
{
	char temp[LEN];

	Person people[N]; // array van N personen

	for (int i = 0; i < N; i++)
	{
		people[i] = readOnePerson();
	}

	printPeople(people);

	return 0;
}

Person readOnePerson(void)
{
	Person person; // HEEL BELANGRIJK!! Persoon aanmaken om alles in op te slaan

	printf("Geef de voornaam: ");
	fgets(person.voornaam, sizeof(person.voornaam), stdin);
	person.voornaam[strcspn(person.voornaam, "\n")] = '\0';

	printf("Geef de achternaam: ");
	fgets(person.achternaam, sizeof(person.achternaam), stdin);
	person.achternaam[strcspn(person.achternaam, "\n")] = '\0';

	return person;
}

void printPeople(Person people[])
{
	printf("\n\nDe personen in de array zijn:\n");

	for (int i = 0; i < N; i++)
	{
		printf("- %s %s\n", people[i].voornaam, people[i].achternaam);
	}
}
