#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "file.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* fp;
    char targetName[128];
    char keyBuf[64];
    char nameBuf[128];
    char ageKey[64];
    int ageValue = 0;
    int found = 0;

    fp = fopen(FILEPATH, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open '%s'.\n", FILEPATH);
        printf("Please run Ex_14_12 first to create the file.\n");
        return 1;
    }

    printf("Name to search for: ");
    gets(targetName);

    while (fscanf(fp, "%s %s", keyBuf, nameBuf) != EOF)
    {
        if (strcmp(keyBuf, "name:") == 0)
        {
            if (strcmp(nameBuf, targetName) == 0)
            {
                fscanf(fp, "%s %d", ageKey, &ageValue);

                printf("\nname: %s\n", nameBuf);
                printf("age: %d\n", ageValue);

                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("\n'%s' doesn't seem to exist in the file.\n", targetName);
    }

    fclose(fp);
    return 0;
}
