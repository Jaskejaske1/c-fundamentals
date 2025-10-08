#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int randomNumber, guess, count = 1;
	printf("Number Guesser (1 - 100)\n");
	srand(time(NULL));

	randomNumber = rand() % 100 + 1;

	printf("Please enter your first guess: ");
	if (scanf("%d%*c", &guess) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	while (guess != randomNumber)
	{
		if (guess < randomNumber)
		{
			printf("too low.\n");
		}
		else if (guess > randomNumber)
		{
			printf("too high.\n");
		}
		printf("try again: ");
		if (scanf("%d%*c", &guess) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
		count++;
	}

	printf("\nCorrect! The number was indeed %d.\n It took you %d tries.\n\n", guess, count);

	return 0;
}