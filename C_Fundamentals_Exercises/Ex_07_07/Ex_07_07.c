#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define SIZE 15
#define COLUMNS 5

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
    int rows = size / columns;

    int row_iter = 0;
    int col_iter = 0;
    int offset = 0;

    int rowSum = 0;
    int colSum = 0;

    for (int i = 0; i < rows; i++)
    {
        rowSum = 0;

        for (int j = 0; j < columns; j++)
        {
            printf("%d ", a[row_iter]);
            rowSum += a[row_iter];
            row_iter++;
        }

        printf("\nRow sum = %d\n", rowSum);
    }

    for (int i = 0; i < columns; i++)
    {
        colSum = 0;
        col_iter = 0;

        for (int j = 0; j < rows; j++)
        {
            colSum += a[col_iter + offset];
            col_iter += columns;
        }
        offset++;

        printf("%d ", colSum);
    }
    printf("= column sum");
}