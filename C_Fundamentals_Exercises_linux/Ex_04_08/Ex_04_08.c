#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[64];
	char firstname[64];

	printf("Please enter your name: ");
	gets(name); // unsafe? => het is oke (voor nu), later fgets()

	printf("Please enter your first name: ");
	gets(firstname);

	printf("%s %s\n\n", firstname, name);
	return 0;
}