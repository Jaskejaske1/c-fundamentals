#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define N 5

#include <stdio.h>

typedef struct {
	char name[LEN];
	char firstname[LEN];
} Person;

void readPerson(Person* person);
void printPerson(Person person);

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
	gets(person->firstname);

	printf("Surname: ");
	gets(person->name);
}

void printPerson(Person person)
{
	printf("%s %s\n", person.firstname, person.name);
}
