#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define AANTAL 5
#define LENGTH 64

void lees_namen(char namen[][LENGTH]);
void print_omgekeerd(char namen[][LENGTH]);

int main(void)
{
	char namen[AANTAL][LENGTH];

	lees_namen(namen);
	print_omgekeerd(namen);

	return 0;
}

void lees_namen(char namen[][LENGTH])
{
	printf("Enter 5 names:\n");
	for (int i = 0; i < AANTAL; i++)
	{
		printf("Geef naam %d: ", i + 1);
		gets(namen[i]);
	}
}

void print_omgekeerd(char namen[][LENGTH])
{
	printf("\nDe namen in omgekeerde volgorde zijn:\n");
	for (int i = AANTAL - 1; i >= 0; i--)
	{
		printf("%s\n", namen[i]);
	}
}