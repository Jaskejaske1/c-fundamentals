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

void findPersonByName(char name[LEN]);
void printPerson(Person p);

int main(void)
{
	char name[LEN];

	printf("What's the name of the person you want to search for? ");
	fgets(name, LEN, stdin);
	name[strcspn(name, "\n")] = '\0';
	findPersonByName(name);

	exit(EXIT_SUCCESS);
}

void findPersonByName(char name[LEN])
{
    FILE* fp;
    Person p;
    int found = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&p, sizeof(Person), 1, fp))
    {
        if (strcmp(name, p.name) == 0) 
        {
            printPerson(p);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No matches found.\n");
    }

    fclose(fp); 
}

void printPerson(Person p)
{
	printf("Name: %s\n", p.name);
	printf("Age: %.2d\n", p.age);
	printf("Salary %.2lf\n\n", p.salary);
}
