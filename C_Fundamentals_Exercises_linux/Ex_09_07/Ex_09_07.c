#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_LIMIT 512
#define NAME_AMOUNT 10


int readNames(char[][LEN_LIMIT]);
void printNames(char[][LEN_LIMIT], int);


int main(void)
{
	char names[NAME_AMOUNT][LEN_LIMIT];
	int nameCount;

	nameCount = readNames(names);
	printNames(names, nameCount);

	return 0;
}


int readNames(char names[][LEN_LIMIT])
{
	char currentName[LEN_LIMIT];

	for (int i = 0; i < NAME_AMOUNT; i++)
	{
		printf("Enter name %d (or 'end' to stop): ", i + 1);

		if (fgets(currentName, LEN_LIMIT, stdin) == NULL)
		{
			printf("Error reading names.\n");
			exit(EXIT_FAILURE);
		}
		currentName[strcspn(currentName, "\n")] = '\0';

		if (strcmp(currentName, "end") != 0)
		{
			strcpy(names[i], currentName);
		}
		else
		{
			return i;
		}
	}
}


void printNames(char names[][LEN_LIMIT], int count)
{
	printf("\nThe names are:\n");

	for (int i = 0; i < count; i++)
	{
		printf("Name %d: %s\n", i + 1, names[i]);
	}
}