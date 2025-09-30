#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printLine(int lengte, char symbool);

int main(void)
{
	printLine(5, '*');
	printLine(3, '#');
	return 0;
}

void printLine(int lengte, char symbool)
{
	int i;
	for (i = 0; i < lengte; i++)
	{
		printf("%c", symbool);
	}
	printf("\n");
}