#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_LIMIT 1024

int isPalindrome(char[]);
void handleUserInput(char[]);

int main(void)
{
	char input[CHAR_LIMIT];

	handleUserInput(input);



	if (isPalindrome(input))
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

	printf("The word '%s' in reverse is '%s'.\n\n", input, reverse);

	return strcmp(input, reverse) == 0; // strcmp returns zero if the strings are the same
}

void handleUserInput(char input[])
{
	printf("Please enter a word to check if it's a palindrome: ");
	gets(input);
	int len = strlen(input);
	if (len >= CHAR_LIMIT)
	{
		printf("The input is too long.\n");
		exit(EXIT_FAILURE);
	}
}