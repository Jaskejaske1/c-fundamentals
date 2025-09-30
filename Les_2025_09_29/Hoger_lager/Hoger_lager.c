#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int randomGetal, gok, pogingen = 0;

	// print header
	printf("Zoek een getal tussen [1, 100]\n");

	// genereer randomGetal
	srand(time(NULL)); // set rand seed
	randomGetal = rand() % 100 + 1;

	// vraag getal voor de eerste keer
	printf("Doe een gok: ");
	scanf("%d%*c", &gok);

	while (gok != randomGetal)
	{
		if (gok > randomGetal)
		{
			printf("Te hoog.\n");
		}
		else
		{
			printf("Te laag.\n");
		}

		// vraag getal opnieuw
		printf("Doe een gok: ");
		scanf("%d%*c", &gok);
		pogingen++;
	}

	printf("Proficiat het getal was inderdaad %d.\n", randomGetal);
	printf("U heeft het gevonden in %d pogingen.\n\n", pogingen);

	return 0;
}