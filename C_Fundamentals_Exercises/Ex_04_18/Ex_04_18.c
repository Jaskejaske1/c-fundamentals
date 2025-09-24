#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[64];
	char firstName[64];
	char street[64];
	int houseNumber;
	int zipCode;
	char townName[64];

	printf("Enter your name: ");
	gets(name);

	printf("Enter your first name: ");
	gets(firstName);

	printf("Enter your street: ");
	gets(street);

	printf("Enter your house number: ");
	scanf("%d%*c", &houseNumber);

	printf("Enter your zip code: ");
	scanf("%d%*c", &zipCode);

	printf("Enter your town name: ");
	gets(townName);

	printf("\n%s   %s\n", firstName, name);
	printf("%s  %d\n", street, houseNumber);
	printf("%d %20s\n", zipCode, townName);

	return 0;
}