#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int getal;

	printf("Geef een getal: ");
	scanf("%d%*c", &getal);

	printf("Het bijhorende karakter is: ");

	switch (getal % 3)
	{
	case 0:
		printf("*");
		break;
	case 1:
		printf("/");
		break;
	case 2:
		printf("+");
		break;
	default:
		printf("<invalid>");
		break;
	}

	printf("\n\n");
	return 0;
}