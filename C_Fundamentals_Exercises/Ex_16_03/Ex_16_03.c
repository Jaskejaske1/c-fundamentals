#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	int month;
	int year;
} Date;

typedef struct
{
	char name[LEN];
	Date birthdate;
} Person;

int read_person(Person* p_person, FILE* fptr);
int calculate(Person person, Date current_date, Person* p_oldest, Person* p_longest);

int main(int argc, char* argv[])
{
	FILE* fptr;
	Person current_person;
	Person oldest_person;
	Person longest_name_person;
	Date current_date;
	int age;
	int is_first_person = 1; // true

	if (argc != 5)
	{
		printf("Please provide 4 arguments in this format: <file.txt> <dd> <mm> <yyyy>\n");
		exit(EXIT_FAILURE);
	}

	current_date.day = atoi(argv[2]);
	current_date.month = atoi(argv[3]);
	current_date.year = atoi(argv[4]);

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Error opening file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("the ages are:\n");

	while (read_person(&current_person, fptr) == 1)
	{
		// initialisatie
		if (is_first_person)
		{
			oldest_person = current_person;
			longest_name_person = current_person;
			is_first_person = 0; // false
		}

		age = calculate(current_person, current_date, &oldest_person, &longest_name_person);

		printf("%s is %d years old\n", current_person.name, age);
	}

	printf("\n%s is the oldest of the persons in the file.\n", oldest_person.name);
	printf("The person with the longest name is: %s\n", longest_name_person.name);

	fclose(fptr);
	return 0;
}

int read_person(Person* p_person, FILE* fptr)
{
    char date_string[LEN];

    if (fgets(p_person->name, LEN, fptr) == NULL)
    {
        return 0;
    }

    p_person->name[strcspn(p_person->name, "\n")] = '\0';

    // datum regel eerst als tekst
    if (fgets(date_string, LEN, fptr) == NULL)
    {
        return 0; // error
    }

	date_string[strcspn(date_string, "\n")] = '\0';

    // datum string -> getallen	
    if (sscanf(date_string, "%d %d %d", &p_person->birthdate.day, &p_person->birthdate.month, &p_person->birthdate.year) != 3)
    {
        return 0; // Formaat klopte niet
    }

    return 1; // succes
}

int calculate(Person person, Date current_date, Person* p_oldest, Person* p_longest)
{
	int age;

	age = current_date.year - person.birthdate.year;

	// maand nog niet geweest?
	if (current_date.month < person.birthdate.month)
	{
		age--;
	}

	// zelfde maand; dag nog niet geweest?
	else if (current_date.month == person.birthdate.month && current_date.day < person.birthdate.day)
	{
		age--;
	}

	// lager = ouder
	// jaar
	if (person.birthdate.year < p_oldest->birthdate.year)
	{
		*p_oldest = person;
	}
	// zelfde jaar
	else if (person.birthdate.year == p_oldest->birthdate.year)
	{
		// maand
		if (person.birthdate.month < p_oldest->birthdate.month)
		{
			*p_oldest = person;
		}
		// zelfde maand
		// dag
		else if (person.birthdate.month == p_oldest->birthdate.month)
		{
			if (person.birthdate.day < p_oldest->birthdate.day)
			{
				*p_oldest = person;
			}
		}
	}

	// langste naam
	if (strlen(person.name) > strlen(p_longest->name))
	{
		*p_longest = person;
	}

	return age;
}