#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define MONLEN 16
#define N 3

#include <stdio.h>
#include <string.h>

typedef struct
{
	int day;
	char month[MONLEN];
	int year;
} Date;

typedef struct
{
	char name[LEN];
	char firstname[LEN];
	Date dateOfBirth;
} Person;

void readPerson(Person* person);
void printPerson(Person person);
void readDate(Date* date);
void printDate(Date date);

int main(void)
{
	Person people[N];

	printf("Enter %d names (first name and surname)\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("Person %d:\n", i + 1);
		readPerson(&people[i]);
	}

	printf("The %d entered names are:\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("%d. ", i + 1);
		printPerson(people[i]);
	}

	return 0;
}

void readPerson(Person* person)
{
	printf("First name: ");
	fgets(person->firstname, LEN, stdin);
	person->firstname[strcspn(person->firstname, "\n")] = '\0';

	printf("Surname: ");
	fgets(person->name, LEN, stdin);
	person->name[strcspn(person->name, "\n")] = '\0';

	printf("Birthday:\n");
	readDate(&person->dateOfBirth);
	
}

void printPerson(Person person)
{
	printf("%s %s\n", person.firstname, person.name);
	printf("Birthday: ");
	printDate(person.dateOfBirth);
}

void readDate(Date* date)
{
	printf("Enter the day: ");
	scanf("%d%*c", &date->day);

	printf("Enter the month: ");
	fgets(date->month, MONLEN, stdin);
	date->month[strcspn(date->month, "\n")] = '\0';

	printf("Enter the year: ");
	scanf("%d%*c", &date->year);
}

void printDate(Date date)
{
	printf("%d %s %d\n", date.day, date.month, date.year);
}
