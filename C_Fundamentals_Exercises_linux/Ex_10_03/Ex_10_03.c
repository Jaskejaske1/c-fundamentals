#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_NAME_LENGTH 128

void readArray(char array[][MAX_NAME_LENGTH]);
void bubbleSort(char array[][MAX_NAME_LENGTH]);
void printArray(char array[][MAX_NAME_LENGTH]);

int main(void)
{
    char array[SIZE][MAX_NAME_LENGTH];

    readArray(array);
    bubbleSort(array);
    printArray(array);

    return 0;
}

void readArray(char array[][MAX_NAME_LENGTH])
{
    int index;

    for (index = 0; index < SIZE; index++)
    {
        printf("Enter name %d: ", index + 1);

        if (gets(array[index]) == NULL)
        {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void bubbleSort(char array[][MAX_NAME_LENGTH])
{
    int passCount;
    int swapped;
    int index;

    for (passCount = 0; passCount < SIZE - 1; passCount++)
    {
        swapped = 0;

        for (index = 0; index < SIZE - 1 - passCount; index++)
        {
            if (strcmp(array[index], array[index + 1]) > 0)
            {
                char temporaryName[MAX_NAME_LENGTH];
                strcpy(temporaryName, array[index]);
                strcpy(array[index], array[index + 1]);
                strcpy(array[index + 1], temporaryName);
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void printArray(char array[][MAX_NAME_LENGTH])
{
    int index;

    printf("Array after sorting:\n");
    for (index = 0; index < SIZE; index++)
    {
        printf("%s\n", array[index]);
    }
}