#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int digit;

	printf("Please enter a digit: ");
	if (scanf("%d%*c", &digit) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	switch (digit)
	{
	case 0:
		printf("You have entered the digit zero.");
		break;
	case 1:
		printf("You have entered the digit one.");
		break;
	case 2:
		printf("You have entered the digit two.");
		break;
	case 3:
		printf("You have entered the digit three.");
		break;
	case 4:
		printf("You have entered the digit four.");
		break;
	case 5:
		printf("You have entered the digit five.");
		break;
	case 6:
		printf("You have entered the digit six.");
		break;
	case 7:
		printf("You have entered the digit seven.");
		break;
	case 8:
		printf("You have entered the digit eight.");
		break;
	case 9:
		printf("You have entered the digit nine.");
		break;
	default:
		printf("The number you entered is not a digit.");
		break;
	}

	printf("\n\n");

	return 0;
}