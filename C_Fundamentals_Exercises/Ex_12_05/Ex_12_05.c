#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void printShortBinary(short value);
short readShort(void);

int main(void)
{
    short value;

    value = readShort();
    printShortBinary(value);
    printf("\n");

    return 0;
}

void printShortBinary(short value)
{
    int bitIndex;
    int mask;

    for (bitIndex = 15; bitIndex >= 0; bitIndex--)
    {
        mask = 1 << bitIndex;

        if (value & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

        if (bitIndex % 4 == 0 && bitIndex != 0)
        {
            printf(" ");
        }
    }
}

short readShort(void)
{
    int temp;

    printf("Enter an integer: ");
    if (scanf("%d", &temp) != 1)
    {
        printf("Error: Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    if (temp < -32768 || temp > 32767)
    {
        printf("Error: Value out of range for type short.\n");
        exit(EXIT_FAILURE);
    }

    return (short)temp;
}