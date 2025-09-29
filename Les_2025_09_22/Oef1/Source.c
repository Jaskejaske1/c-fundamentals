#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int tijd1, tijd2;
	int som;
	int uren, minuten;

	printf("Geef de eerste tijd in minuten: ");
	scanf("%d%*c", &tijd1);

	printf("Geef de tweede tijd in minuten: ");
	scanf("%d%*c", &tijd2);

	som = tijd1 + tijd2;

	if (som >= 60)
	{
		uren = som / 60;
		minuten = som % 60;
		if (uren)
			printf("De totale tijd is: %d uur en %d minuten.", uren, minuten);
		else
			printf("De totale tijd is: %d uren en %d minuten.", uren, minuten);
	}
	else
	{
		printf("De totale tijd is minder dan 1 uur. In minuten is dit: %d.", som);
	}

	printf("\n\n"); // Duidelijke scheiding van programma en Visual studio rommel

	return 0;
}