#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "file.txt"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    FILE* fp;

    fp = fopen(FILEPATH, "r");

    if (fp == NULL)
    {
        printf("Error: Could not open '%s'.\n", FILEPATH);
        printf("Please run Ex_14_12 first to create the file.\n");
        return 1;
    }

    printf("Data from File:\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\nEOF\n");

    fclose(fp);

    return 0;
}