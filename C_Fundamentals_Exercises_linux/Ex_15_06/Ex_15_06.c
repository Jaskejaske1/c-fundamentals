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

void readPerson(Person* p);

int main(void)
{
	int count;
	Person p;
	FILE* fp;

	fp = fopen(FILENAME, "wb");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		exit(EXIT_FAILURE);
	}

	printf("How many people do you want to enter? ");
	scanf("%d%*c", &count);

	for (int i = 0; i < count; i++)
	{
		readPerson(&p);

		fwrite(&p, sizeof(Person), 1, fp);
	}

	fclose(fp);
	exit(EXIT_SUCCESS);
}

void readPerson(Person* p)
{
	printf("Enter name: ");
	fgets(p->name, LEN, stdin);
	p->name[strcspn(p->name, "\n")] = '\0';

	printf("Enter age: ");
	scanf("%d%*c", &p->age);

	printf("Enter salary: ");
	scanf("%lf%*c", &p->salary);
}