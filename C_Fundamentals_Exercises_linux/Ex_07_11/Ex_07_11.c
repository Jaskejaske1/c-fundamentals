#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100
#define STOP 999

int ReadArray(int[]);
void PrintArray(int[], int);
double CalcMean(int[], int);
int GetMax(int[], int);

int main(void)
{
    int row[MAX];
    int size, max;
    double mean;

    size = ReadArray(row);
    mean = CalcMean(row, size);
    max = GetMax(row, size);
    PrintArray(row, size);

    printf("The mean is: %lf\n", mean);
    printf("The max value entered is: %d\n", max);

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

double CalcMean(int array[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
}

int GetMax(int array[], int size)
{
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}