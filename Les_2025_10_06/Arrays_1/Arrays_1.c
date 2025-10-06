#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define AANTAL 5

int main(void)
{
	int getallen[AANTAL];

	for (int i = 0; i < AANTAL; i++)
	{
		printf("Geef getal nr. %d: ", i + 1);
		if (scanf("%d%*c", &getallen[i]) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	}

	printf("De ingegeven getallen in omgekeerde volgorde\n");

	for (int i = AANTAL - 1; i >= 0; i--)
	{
		printf("Getal %d: %d\n", i + 1, getallen[i]);
	}
	printf("\n");
	return 0;
}