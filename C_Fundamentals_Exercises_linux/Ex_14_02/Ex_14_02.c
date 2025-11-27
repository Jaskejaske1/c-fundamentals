/*
Write a program that copies the text file line by line to a new file.
*/

#define _CRT_SECURE_NO_WARNINGS
#define SOURCE_FILEPATH "file.txt"
#define DESTINATION_FILEPATH "file2.txt"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp_source;
	FILE* fp_dest;
	char line[BUFSIZ];

	if ((fp_source = fopen(SOURCE_FILEPATH, "r")) == NULL)
	{
		printf("The file at \"%s\" cannot be opened for reading!\nDoes it exist?\n", SOURCE_FILEPATH);
		exit(1);
	}

	if ((fp_dest = fopen(DESTINATION_FILEPATH, "w")) == NULL)
	{
		printf("The file at \"%s\" cannot be opened for writing!\n", DESTINATION_FILEPATH);
		fclose(fp_source);
		exit(1);
	}

	while (fgets(line, BUFSIZ, fp_source) != NULL)
	{
		fputs(line, fp_dest);
	}

	fclose(fp_source);
	fclose(fp_dest);

	printf("File copy completed successfully.\n");

	return 0;
}