#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LINES 22
#define LENGTH 40

int main(void)
{
	char symbol = 219;

	for (int i = 1; i <= LINES; i++)
	{
		for (int j = 1; j <= LENGTH; j++)
		{
			printf("%c", symbol);
		}
		printf("\n");
	}

	printf("\n\n");

	return 0;
}