#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

char menu(void);
void add(FILE*);
void list(FILE*);
void search(FILE*);
void takeOut(FILE*);
void printPhone(Phone*, int);
void line(void);

int main(void)
{
	FILE* fp;
	int stop;

	if ((fp = fopen(FILENAME, "r+b")) == NULL)
	{
		if ((fp = fopen(FILENAME, "w+b")) == NULL)
		{
			printf("\"%s\" cannot be opened\n", FILENAME);
			exit(1);
		}
	}

	stop = 0;
	while (!stop)
	{
		switch (menu())
		{
		case 'e': stop = 1; break;
		case 'a': add(fp); break;
		case 'l': list(fp); break;
		case 's': search(fp); break;
		case 'r': takeOut(fp); break;
		}
	}
	fclose(fp);
	return 0;
}

char menu(void)
{
	char s[16]; int i;
	for (i = 0; i < MENU_SIZE; i++)
	{
		printf(" %s : %s\n", menutext[i][0], menutext[i][1]);
	}
	printf("Your choice: ");
	gets(s);
	return s[0];
}

void add(FILE* fp)
{
	Phone a;
	Phone* pa;
	pa = &a;
	memset(pa, '\0', sizeof(Phone)); // set all bytes in Phone to \0
	printf("Name: ");
	gets(pa->name);
	printf("Phone Number: ");
	gets(pa->phoneNr);
	fseek(fp, 0, SEEK_END);
	fwrite(pa, sizeof(Phone), 1, fp);
}

void list(FILE* fp)
{
	Phone a;
	Phone* pa;
	int recnr = 0;
	pa = &a;
	line();
	fseek(fp, 0, SEEK_SET);
	while (fread(pa, sizeof(Phone), 1, fp) > 0)
	{
		// removed records with name[0]=='\0' cannot be printed
		if (pa->name[0] != '\0')
			printPhone(pa, recnr);
		recnr++;
	}
	line();
}

void search(FILE* fp)
{
	Phone p;
	char searchName[32];
	int recnr = 0;
	int found = 0;

	printf("Enter part of the name to search: ");
	gets(searchName);

	line();
	fseek(fp, 0, SEEK_SET); // rewind to start

	while (fread(&p, sizeof(Phone), 1, fp) == 1)
	{
		if (p.name[0] != '\0')
		{
			if (strstr(p.name, searchName) != NULL)
			{
				printPhone(&p, recnr);
				found = 1;
			}
		}
		recnr++;
	}

	if (!found)
	{
		printf("No records found matching: \"%s\".\n", searchName);
	}
	line();
}

void takeOut(FILE* fp)
{
	int recnr;
	Phone p;        // To hold the data we read to check
	Phone empty;    // To hold the zeros we write
	long fileSize;
	long offset;
	char buffer[16];

	printf("Enter the Record Number to delete: ");
	gets(buffer);
	recnr = atoi(buffer);

	offset = recnr * sizeof(Phone);

	// 1. Check if record is within file bounds
	fseek(fp, 0, SEEK_END);
	fileSize = ftell(fp);

	if (offset >= fileSize || offset < 0)
	{
		printf("Error: Record number %d does not exist.\n", recnr);
		return;
	}

	// 2. Jump to the record to CHECK it first
	fseek(fp, offset, SEEK_SET);

	// Read the record to see if it's already empty
	fread(&p, sizeof(Phone), 1, fp);

	if (p.name[0] == '\0')
	{
		printf("Error: Record %d is already removed.\n", recnr);
		return;
	}

	// 3. CRITICAL STEP: Move the cursor BACK!
	// fread moved us forward 1 record. We must step back to overwrite the correct one.
	fseek(fp, offset, SEEK_SET);
	// Alternatively: fseek(fp, -((long)sizeof(Phone)), SEEK_CUR);

	// 4. Overwrite with zeros
	memset(&empty, 0, sizeof(Phone));

	if (fwrite(&empty, sizeof(Phone), 1, fp) == 1)
	{
		printf("Record %d has been removed.\n", recnr);
	}
	else
	{
		printf("Error writing to file.\n");
	}
}

void printPhone(Phone* pa, int recnr)
{
	printf("%3d : %20s %12s\n", recnr, pa->name, pa->phoneNr);
}

void line(void)
{
	int i;
	for (i = 0; i < 50; i++)
		printf("-");
	printf("\n");
}