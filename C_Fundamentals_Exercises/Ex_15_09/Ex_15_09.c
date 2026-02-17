#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define FILENAME_OLD "people_old.dat"
#define FILENAME_NEW "people_new.dat"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[LEN];
	int age;
	double salary;
} PersonOld;

typedef struct
{
	char first_name[LEN];
	char last_name[LEN];
	int age;
	double salary;
} PersonNew;

// Updated Prototype:
// 1. We use '*' to pass a pointer (address) instead of the whole struct.
// 2. We use 'const' to promise we won't change the data inside.
void printPerson(const PersonNew* p);

int main(void)
{
	FILE* fp_old;
	FILE* fp_new;
	PersonOld person_old;
	PersonNew person_new;

	fp_old = fopen(FILENAME_OLD, "rb");
	fp_new = fopen(FILENAME_NEW, "wb");

	if (fp_old == NULL)
	{
		printf("Error opening original file.\n");
		exit(EXIT_FAILURE);
	}
	if (fp_new == NULL)
	{
		printf("Error opening new file.\n");
		exit(EXIT_FAILURE);
	}

	// fread returns the number of items read. 
	// loops while it successfully reads 1 item.
	while (fread(&person_old, sizeof(PersonOld), 1, fp_old) == 1)
	{
		printf("Enter the first name of %s: ", person_old.name);
		fgets(person_new.first_name, LEN, stdin);
		person_new.first_name[strcspn(person_new.first_name, "\n")] = '\0';

		strcpy(person_new.last_name, person_old.name);
		person_new.age = person_old.age;
		person_new.salary = person_old.salary;

		fwrite(&person_new, sizeof(PersonNew), 1, fp_new);
	}

	fclose(fp_old);
	fp_old = NULL;
	fclose(fp_new);
	fp_new = NULL;

	// Re-open the new file to verify
	fp_new = fopen(FILENAME_NEW, "rb");

	if (fp_new == NULL)
	{
		printf("Error opening new file.\n");
		exit(EXIT_FAILURE);
	}

	while (fread(&person_new, sizeof(PersonNew), 1, fp_new) == 1)
	{
		// Pass the ADDRESS (&) of the struct, not the struct itself
		printPerson(&person_new);
	}

	fclose(fp_new);

	return EXIT_SUCCESS; // 'return' is often preferred over 'exit' at the end of main
}

// The function receives a PersonNew pointer 'p'
void printPerson(const PersonNew* p)
{
	// Because 'p' is a pointer, we use the arrow '->' 
	// instead of the dot '.' to access fields.
	printf("First name: %s\n", p->first_name);
	printf("Last name: %s\n", p->last_name);
	printf("Age: %d\n", p->age);
	printf("Salary: %.2lf\n\n", p->salary);
}