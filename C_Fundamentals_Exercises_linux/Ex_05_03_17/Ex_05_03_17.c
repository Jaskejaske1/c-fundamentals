#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int width;
	char symbol = 219;

	printf("Welcome to ZIGZAG World!\n");
	printf("How wide do you want your ZIGZAG line?\n");

	printf("Enter a width between 3 and 60: ");
	if (scanf("%d%*c", &width) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	while (width < 3 || width > 60)
	{
		printf("Wrong width. Please enter a width between 3 and 60: ");
		if (scanf("%d%*c", &width) != 1)
		{
			printf("Invalid input.\n\n");
			return 1;
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int amountOfSpaces = 1; amountOfSpaces <= i; amountOfSpaces++)
		{
			printf(" ");
		}
		printf("%c\n", symbol);
	}

	for (int i = (width - 1); i >= (int)((float)width / 2); i--)
	{
		for (int amountOfSpaces = 1; amountOfSpaces < i; amountOfSpaces++)
		{
			printf(" ");
		}
		printf("%c\n", symbol);
	}

	for (int i = 0; i < (int)((float)width / 4); i++)
	{
		for (int amountOfSpaces = 1; amountOfSpaces <= i + (int)((float)width / 2); amountOfSpaces++)
		{
			printf(" ");
		}
		printf("%c\n", symbol);
	}

	for (int i = (int)((float)width / 8) + (int)((float)width / 10); i >= 0; i--)
	{
		for (int amountOfSpaces = 1; amountOfSpaces < i + (int)((float)width / 2); amountOfSpaces++)
		{
			printf(" ");
		}
		printf("%c\n", symbol);
	}

	return 0;
}