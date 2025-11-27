#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define N 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Required for atoi

typedef struct
{
	int day;
	char month[LEN];
	int year;
} Date;

typedef struct
{
	char firstname[LEN];
	char surname[LEN];
	Date birthDate;
} Person;

Person readOnePerson();
void printPeople(Person people[]);
void readDate(Date* p_date);
void printDate(Date date); // We will also update printPeople to use this

int main(void)
{
	Person people[N];

	for (int i = 0; i < N; i++)
	{
		printf("\n--- Enter details for Person %d ---\n", i + 1);
		people[i] = readOnePerson();
	}

	printPeople(people);

	return 0;
}

Person readOnePerson(void)
{
	Person person;

	printf("Enter the firstname: ");
	fgets(person.firstname, sizeof(person.firstname), stdin);
	person.firstname[strcspn(person.firstname, "\n")] = '\0';

	printf("Enter the surname: ");
	fgets(person.surname, sizeof(person.surname), stdin);
	person.surname[strcspn(person.surname, "\n")] = '\0';

	readDate(&(person.birthDate));

	return person;
}

void readDate(Date* p_date)
{
	char buffer[LEN]; // Temporary buffer to convert text to numbers

	do {
		printf("Enter the day (1-31): ");
		// Use fgets to safely read the line
		fgets(buffer, LEN, stdin);
		// Convert string to integer
		p_date->day = atoi(buffer);
	} while (p_date->day < 1 || p_date->day > 31);

	printf("Enter the month: ");
	fgets(p_date->month, sizeof(p_date->month), stdin);
	p_date->month[strcspn(p_date->month, "\n")] = '\0';

	printf("Enter the year: ");
	// Read year safely using fgets + atoi
	fgets(buffer, LEN, stdin);
	p_date->year = atoi(buffer);
}

void printPeople(Person people[])
{
	printf("\n\nThe people in the array are:\n");

	for (int i = 0; i < N; i++)
	{
		printf("--------------------\n");
		printf("Name: %s %s\n", people[i].firstname, people[i].surname);
		// Actually call the printDate function here!
		printDate(people[i].birthDate);
	}
}

void printDate(Date date)
{
	printf("Birthdate: %d %s %d\n", date.day, date.month, date.year);
}