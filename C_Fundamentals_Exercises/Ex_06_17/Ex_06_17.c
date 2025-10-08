#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void empty_square(char symbol, int size);
void filled_square(char symbol, int size);

int main(void)
{
	int choice;
	char symbol = 219;

	do
	{
		do
		{
			printf("What do you choose?\n");
			printf("\t 1. Draw an empty square\n");
			printf("\t 2. Draw a filled square\n");
			printf("\t 3. Stop\n");

			if (scanf("%d%*c", &choice) != 1)
			{
				printf("Invalid input.\n\n");
				break;
			}

			if (choice < 1 || choice > 3)
			{
				printf("Enter a valid choice: 1, 2 or 3!\n\n");
			}

		} while (choice < 1 || choice > 3);

		switch (choice)
		{
		case 1:
			empty_square(symbol, SIZE);
			break;
		case 2:
			filled_square(symbol, SIZE);
			break;
		case 3:
			printf("Thanks for playing with us!\n");
			break;
		}
	} while (choice != 3);

	printf("\n");
	return 0;
}

void empty_square(char symbol, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c%c", symbol, symbol);
	}

	printf("\n");
	for (int i = 0; i < (size - 2); i++)
	{
		printf("%c%c", symbol, symbol);

		for (int j = 0; j < (size - 2); j++)
		{
			printf("  ");
		}

		printf("%c%c", symbol, symbol);

		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		printf("%c%c", symbol, symbol);
	}
	
	printf("\n\n");
}

void filled_square(char symbol, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%c%c", symbol, symbol);
		}
		printf("\n");
	}
	printf("\n");
}