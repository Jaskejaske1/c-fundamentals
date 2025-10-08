#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LENGTH 32

void omzetten(char[], char[]);

int main(void)
{
	char in[LENGTH];
	char uit[LENGTH];

	printf("Geef een string: ");

	gets(in);
	omzetten(in, uit);

	printf("in = %s\nuit = %s\n", in, uit);
	return 0;
}

void omzetten(char in[], char uit[])
{
	int i = 0;

	while (in[i] != '\0')
	{
		uit[i] = in[i];
		if (uit[i] >= 'a' && uit[i] <= 'z')
		{
			uit[i] += 'A' - 'a';
		}
		++i;
	}
	uit[i] = '\0';
}