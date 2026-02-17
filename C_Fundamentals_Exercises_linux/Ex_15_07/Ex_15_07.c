#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define FILENAME "people.dat"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[LEN];
	int age;
	double salary;
} Person;

void printPerson(Person* p);

int main(void)
{
	FILE* fp;
	Person p;

	fp = fopen(FILENAME, "rb");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		exit(EXIT_FAILURE);
	}

	while (fread(&p, sizeof(Person), 1, fp)) // IMPORTANT!
	{
		printPerson(&p);
	}

	exit(EXIT_SUCCESS);
}

void printPerson(Person* p)
{
	printf("Name: %s\n", p->name);
	printf("Age: %.2d\n", p->age);
	printf("Salary %.2lf\n\n", p->salary);
}
