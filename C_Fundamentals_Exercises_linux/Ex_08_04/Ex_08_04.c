#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CHAR_LIMIT 1024

int isPalindrome(char[]);
void handleInput(char[]);
void cleanInput(char[], char[]);

int main(void)
{
	char input[CHAR_LIMIT];
	char cleaned[CHAR_LIMIT];

	handleInput(input);
	cleanInput(input, cleaned);

	if (isPalindrome(cleaned))
	{
		printf("So, '%s' is, in fact, a palindrome!\n", input);
	}
	else
	{
		printf("So, '%s' is not a palindrome.\n", input);
	}

	return 0;
}

int isPalindrome(char input[])
{
	int len = strlen(input);
	char reverse[CHAR_LIMIT];

	reverse[len] = '\0';

	for (int i = 0; i < len; i++)
	{
		reverse[len - i - 1] = input[i];
	}

	printf("The normalized sentence '%s' in reverse is '%s'.\n\n", input, reverse);

	return strcmp(input, reverse) == 0; // strcmp returns zero if the strings are the same
}

void handleInput(char input[])
{
	printf("Please enter a sentence to check if it's a palindrome: ");
	// gets(input);

	fgets(input, CHAR_LIMIT, stdin);
	input[strcspn(input, "\n")] = '\0';

	int len = strlen(input);
	if (len >= CHAR_LIMIT - 1) // - 1 so there is space for \0 at index 1024
	{
		printf("The input is too long.\n");
		exit(EXIT_FAILURE);
	}
}

void cleanInput(char input[], char output[])
{
	int len = strlen(input);
	int outputIterator = 0;

	for (int i = 0; i < len; i++)
	{
		if (isalpha(input[i]))
		{
			output[outputIterator] = tolower(input[i]);
			outputIterator++;
		}
	}
	output[outputIterator] = '\0';
}