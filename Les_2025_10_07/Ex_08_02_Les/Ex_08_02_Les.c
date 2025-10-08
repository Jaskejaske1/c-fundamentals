#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define WORDLENGTH 16
#define LENGTH 64

int main(void)
{
	char s1[WORDLENGTH];
	char s2[WORDLENGTH];
	char s3[WORDLENGTH];
	char s4[LENGTH];

	printf("Enter the first word: ");
	if (scanf("%s%*c", s1) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter the second word: ");
	if (scanf("%s%*c", s2) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter the third word: ");
	if (scanf("%s%*c", s3) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	strcpy(s4, s1);
	strcat(s4, " ");
	strcat(s4, s2);
	strcat(s4, " ");
	strcat(s4, s3);

	printf("\n%s\n", s4);

	return 0;
}