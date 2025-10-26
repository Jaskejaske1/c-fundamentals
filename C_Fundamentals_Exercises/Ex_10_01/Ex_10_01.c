/*
Ex_10_01.c
Write a program with functions.
- In the main function, an array of 10 integers is declared.
- A first function reads the 10 integers and stores them in the
          array.
- A second function swaps the first integer with the min value
          present in the array. Swapping must be done in the same
          array, without using a second array. Using an extra auxiliary
          variable is allowed. All other numbers need to stay in their
          original places.
- A third function prints the array after swapping.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void readArray(int array[]);
void swap(int array[]);
void printArray(int array[]);

int main(void)
{
    int array[SIZE];

    readArray(array);
    swap(array);
    printArray(array);

    return 0;
}

void readArray(int array[])
{
    printf("Enter 10 values: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d%*c", &array[i]) != 1)
        {
            printf("Error: invalid input.\n\n");
            exit(EXIT_FAILURE);
        }
    }
}

void swap(int array[])
{
    int min_index = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (array[i] < array[min_index])
        {
            min_index = i;
        }
    }

    if (min_index != 0)
    {
        int temp = array[0];
        array[0] = array[min_index];
        array[min_index] = temp;
    }
}

void printArray(int array[])
{
    printf("Swapped array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
