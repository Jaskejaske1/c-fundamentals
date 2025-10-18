#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define SIZE 12 
#define COLUMNS 3

void ReadArray(int a[], int size);
void PrintMatrix(int a[], int size, int columns);

int main(void)
{
    int a[SIZE];
    ReadArray(a, SIZE);
    PrintMatrix(a, SIZE, COLUMNS);
    return 0;
}

void ReadArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d%*c", &a[i]);
    }
    printf("\n");
}

void PrintMatrix(int a[], int size, int columns)
{
    int iterator = 0;

    for (int i = 0; i < (size / columns); i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", a[iterator]);
            iterator++;
        }
        printf("\n");
    }
}