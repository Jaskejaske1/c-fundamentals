#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void readFirstPart(int array[]);
int readLastValue(void);
void insertValue(int array[], int value);
void printArray(int array[]);

int main(void)
{
    int array[SIZE];
    int lastValue;

    readFirstPart(array);
    lastValue = readLastValue();
    insertValue(array, lastValue);
    printArray(array);

    return 0;
}

void readFirstPart(int array[])
{
    int index;

    for (index = 0; index < SIZE - 1; index++)
    {
        printf("Enter integer %d (ascending order): ", index + 1);
        if (scanf("%d", &array[index]) != 1)
        {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }

        if (index > 0)
        {
            if (array[index] <= array[index - 1])
            {
                printf("Error: Numbers are not in ascending order. Program will stop.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

int readLastValue(void)
{
    int value;
    printf("\nEnter an integer to insert into the array: ");
    if (scanf("%d", &value) != 1)
    {
        printf("Error: Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

void insertValue(int array[], int value)
{
    int position = 0;
    int index;

    while (position < SIZE - 1 && array[position] < value)
    {
        position++;
    }

    for (index = SIZE - 1; index > position; index--)
    {
        array[index] = array[index - 1];
    }

    array[position] = value;
}

void printArray(int array[])
{
    int index;

    printf("\nNew array of %d integers:\n", SIZE);
    for (index = 0; index < SIZE; index++)
    {
        printf("%d ", array[index]);
    }
    printf("\n");
}