#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printline(int number, char c);

int main(void)
{
	printline(40, '*');
	printline(50, '+');
	printline(12, '-');
	return 0;
}

void printline(int number, char c)
{
	for (int i = 0; i < number; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}