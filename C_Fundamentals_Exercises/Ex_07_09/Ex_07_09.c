#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100
#define STOP 999

int ReadArray(int[]);
void PrintArray(int[], int);

int main(void)
{
    int row[MAX];
    int size;

    size = ReadArray(row);
    PrintArray(row, size);

    return 0;
}

int ReadArray(int array[])
{
    int current, count = 0;

    do
    {
        printf("Enter number %d: ", count + 1);
        scanf("%d%*c", &current);
        if (current != STOP)
        {
            array[count] = current;
            count++;
        }
        
    } while (current != STOP);
    printf("\n");

    return count;
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Number %d: %d\n", i + 1, array[i]);
    }
    printf("\n");
}