#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

int ReadSize(int, int);
void ReadArray(int[], int);
void PrintArray(int[], int);

int main(void)
{
    int row[MAX];
    int size;

    size = ReadSize(0, MAX);
    ReadArray(row, size);
    PrintArray(row, size);

    return 0;
}

int ReadSize(int start, int stop)
{
    int size;
    printf("Enter the size in the interval [0 - 100]: ");
    do
    {
        scanf("%d%*c", &size);
    } while (size < 0 && size > 100);
    printf("\n");
    return size;
}

void ReadArray(int array[], int size)
{
    int current;

    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d%*c", &current);
        array[i] = current;
    }
    printf("\n");
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Number %d: %d\n", i + 1, array[i]);
    }
    printf("\n");
}