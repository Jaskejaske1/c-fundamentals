#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define FILENAME "people_new.dat"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char first_name[LEN];
	char last_name[LEN];
	int age;
	double salary;
} Person;

// 1. We use '*' to pass a pointer (address) instead of the whole struct.
// 2. We use 'const' to promise we won't change the data inside.
void printPerson(const Person* p);

int main(void)
{
	FILE* fp;
	Person person;
	Person max_earner;
	int found_someone = 0;

	max_earner.salary = -1;

	fp = fopen(FILENAME, "rb");

	if (fp == NULL)
	{
		printf("Error opening file.\n");
		exit(EXIT_FAILURE);
	}

	// find max earner
	while (fread(&person, sizeof(Person), 1, fp) == 1)
	{
		found_someone = 1;
		if (person.salary > max_earner.salary)
		{
			max_earner = person;
		}
	}

	fclose(fp);
	fp = NULL;

	if (found_someone)
	{
		printf("The person with the highest salary is:\n");
		printPerson(&max_earner);
	}
	else
	{
		printf("The file was empty!\n");
	}

	return EXIT_SUCCESS;
}

// The function receives a Person pointer 'p'
void printPerson(const Person* p)
{
	printf("First name: %s\n", p->first_name);
	printf("Last name: %s\n", p->last_name);
	printf("Age: %d\n", p->age);
	printf("Salary: %.2lf\n\n", p->salary);
}