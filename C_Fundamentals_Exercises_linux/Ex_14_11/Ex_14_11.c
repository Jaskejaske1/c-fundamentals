#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILEPATH "file.txt"

int main()
{
    FILE* fp;
    char buffer[BUFSIZ];
    char pattern[128];
    int lineNumber = 1;

    fp = fopen(FILEPATH, "r");
    if (fp == NULL)
    {
        printf("The file at \"%s\" cannot be opened for reading!\nDoes it exist?\n", FILEPATH);
        return 1;
    }

    printf("Enter pattern to search: ");
    gets(pattern);

    printf("\nResults:\n");

    while (fgets(buffer, BUFSIZ, fp) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0;

        if (strstr(buffer, pattern) != NULL)
        {
            printf("Line %d: %s\n", lineNumber, buffer);
        }
        lineNumber++;
    }

    fclose(fp);
    return 0;
}