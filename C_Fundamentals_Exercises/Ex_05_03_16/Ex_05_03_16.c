#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char symbol = 219;
	int width;
	char choice = 'n';
	int spaceCounter = 0;

	printf("This program builds a tower upside down!\n");

	do
	{
		printf("How wide should the tower be?\n");

		do
		{
			printf("(enter an odd width between 3 and 15)\n");
			if (scanf("%d%*c", &width) != 1)
			{
				printf("Invalid input.\n\n");
				// clearInputBuffer();
				return 1;
			}
			// clearInputBuffer();

		} while (width % 2 == 0 || width > 15 || width < 3);

		for (width; width >= 1; width -= 2)
		{
			// printf("DEBUG: Width is %d.\n", width);
			for (int lineCount = 1; lineCount <= width; lineCount++)
			{
				for (int spaces = 1; spaces <= spaceCounter; spaces++)
				{
					printf("  ");
				}
				for (int symbolCount = 1; symbolCount <= width; symbolCount++)
				{
					printf("%c%c", symbol, symbol);
				}
				printf("\n");
			}

			spaceCounter++;
		}

		do
		{
			printf("Do you want to build another tower? (y/n) ");
			if (scanf("%c%*c", &choice) != 1)
			{
				printf("Invalid input, try again.\n");
				// clearInputBuffer();
				return 1;
			}
			// clearInputBuffer();

		} while (!(choice == 'y' || choice == 'n'));
		
	} while (choice == 'y');

	printf("Bye bye!\n\n");

	return 0;
}

/*
* Ik heb even opgezocht hoe je de scanf input buffer kan flushen
* Dit is het resultaat.
* Ik zou dit kunnen gebruiken NA de invalid input checks, indien deze deze niet failen.
* Bv. Input: "5 5" => eerste 5 gaat in width, spatie wordt genegeerd, tweede 5 blijft
* in de input buffer over. Deze zou dan moeten geflusht worden zodat de volgende scanf-call
* niet verder gaat zonder te wachten op input.
* 
* Ik laat dit in commentaar staat aangezien we dit niet gezien hebben.
* 
* 
void clearInputBuffer(void)
{
	int c;
	while ( (c = getchar()) != '\n' && c != EOF);
}
*/