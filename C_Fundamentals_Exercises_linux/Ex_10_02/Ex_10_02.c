// Ex_10_02.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void readArray(int array[]);
void bubbleSort(int array[]);
void printArray(int array[]);

int main(void)
{
    int array[SIZE];

    readArray(array);
    bubbleSort(array);
    printArray(array);

    return 0;
}

void readArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void bubbleSort(int array[])
{
    int passCount;
    int swapped;

    for (passCount = 0; passCount < SIZE - 1; passCount++)
    {
        swapped = 0;

        for (int i = 0; i < SIZE - 1 - passCount; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temporary = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temporary;
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void printArray(int array[])
{
    printf("Array after sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}