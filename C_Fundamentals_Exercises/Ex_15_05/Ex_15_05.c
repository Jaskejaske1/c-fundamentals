#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define N 3

#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[LEN];
	char town[LEN];
} Person;

void readPerson(Person* p);
int searchTown(Person p[], Person* searchKey);

int main(void)
{
	Person people[N];
	Person target;
	int found;

	for (int i = 0; i < N; i++)
	{
		readPerson(&people[i]);
	}

	printf("==========================================================\n");

	printf("Enter the name of the person you want to search for: ");
	fgets(target.name, LEN, stdin);
	target.name[strcspn(target.name, "\n")] = '\0';

	found = searchTown(people, &target);

	if (found)
	{
		printf("This person lives in %s\n", target.town);
	}
	else
	{
		printf("This person was not found in the list.\n");
	}

	return 0;
}

void readPerson(Person* p)
{
	printf("Enter name: ");
	fgets(p->name, LEN, stdin);
	p->name[strcspn(p->name, "\n")] = '\0';

	printf("Enter town or city: ");
	fgets(p->town, LEN, stdin);
	p->town[strcspn(p->town, "\n")] = '\0';
}

int searchTown(Person p[], Person* searchKey)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(p[i].name, searchKey->name) == 0)
		{
			strcpy(searchKey->town, p[i].town);
			return 1;
		}
	}
	return 0;
}