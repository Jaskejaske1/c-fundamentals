#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 512

int main(void)
{
	char word[LIMIT];
	printf("Enter a word: ");
	fgets(word, LIMIT, stdin);
	word[strcspn(word, "\n")] = '\0';
	return 0;
}

readMorse(char letter)
{
	const char* morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",NULL };
	
	letter = tolower(letter);

	if (letter < 'a' || letter > 'z')
	{
		printf("You did not enter a valid letter.\n");
		exit(EXIT_FAILURE);
	}
	letter = letter - 'a';

	printf("%s ", morse[letter]);
}