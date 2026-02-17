#define _CRT_SECURE_NO_WARNINGS
#define FILEPATH "file.txt"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amount, i, age;
    char name[128];
    FILE* fp;

    fp = fopen(FILEPATH, "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("For how many people do you want to enter data? ");
    scanf("%d%*c", &amount);

    for (i = 0; i < amount; i++)
    {
        printf("Enter name and age: ");
        scanf("%s %d%*c", name, &age);

        fprintf(fp, "name: %s\n", name);
        fprintf(fp, "age: %d\n\n", age); // exra \n for blank line
    }

    fclose(fp);

    printf("\nData has been successfully written to '%s'.\n", FILEPATH);

    return 0;
}