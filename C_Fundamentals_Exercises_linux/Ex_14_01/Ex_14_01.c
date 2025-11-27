/*
Use a text editor to create a text file that contains a few lines of text.
Write a program that reads the text file line by line and writes everything to the screen.
*/

#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "C:\\Users\\Jaske\\source\\file.txt"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char line[BUFSIZ];

	if ((fp = fopen(FILEPATH, "r")) == NULL)
	{
		printf("The file at \"%s\" cannot be opened!\nDoes it exist?\n", FILEPATH);
		exit(1);
	}

	while (fgets(line, BUFSIZ, fp) != NULL)
	{
		printf("%s", line);
	}

	fclose(fp);
	printf("\n");

	return 0;
}