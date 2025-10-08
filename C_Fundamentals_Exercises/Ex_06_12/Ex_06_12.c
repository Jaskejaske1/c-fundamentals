#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw_bar(int score, char symbol);

int main(void)
{
	char symbol;
	int score;

	printf("What symbol would you like to use?: ");
	if (scanf("%c", &symbol) != 1)
	{
		return 1;
	}

	printf("Please enter the scores: ");

	do
	{
		if (scanf("%d", &score) != 1)
		{
			printf("Invalid character detected!\n");
			break;
		}

		if (score > 0)
		{
			draw_bar(score, symbol);
		}
	} while (score > 0);

	return 0;
}

void draw_bar(int score, char symbol)
{
	printf("score = %d\t", score);
	for (int i = 0; i < score; i++)
	{
		printf("%c", symbol);
	}
	printf("\n");
}
