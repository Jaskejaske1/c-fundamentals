#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	char letter;
	const char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",NULL};

	printf("Enter a letter: ");
	(void)scanf("%c%*c", &letter);
	letter = tolower(letter);

	if (letter < 'a' || letter > 'z')
	{
		printf("You did not enter a valid letter.\n");
		exit(EXIT_FAILURE);
	}
	letter = letter - 'a';

	printf("Corresponding Morse code: %s\n", morse[letter]);

	return 0;
}