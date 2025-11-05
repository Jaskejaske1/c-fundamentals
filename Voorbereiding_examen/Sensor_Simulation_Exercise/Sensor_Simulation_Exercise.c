/*
    -----------------------------------------------------------
    Exercise 1: Binary Sensor Data Simulation
    -----------------------------------------------------------

    Class: 1EICT
    Name: Savels
    Firstname: Jasper

    Goal:
    Simulate 8 sensors that randomly send ON/OFF data.
    Store each reading as a bit in a 16-bit integer array.

    Requirements:
    - Use arrays, for-loops, while-loops, if-statements, switch-statements.
    - Use bit shifting (<<, >>) and bit masking (&, |).
    - Use srand() and rand() for random data generation.
    - Use precompiler directives for constants. ( #define )
    - Use the following libraries:
        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

    Function Signatures:
        void GenerateSensorData(unsigned short data[], int count);
        void PrintData(unsigned short data[], int count, int mode);

    Functionality:
        - GenerateSensorData:
            Generates random sensor data for each entry in the array.
            Each reading (16 bits) should be filled using random bits (0 or 1).
            e.g.:
                reading 1 : 0111 0001 1111 0000
                reading 2 : 1100 0000 0000 0000

                [reading 1,reading 2, etc..., MAX_READINGS]

        - PrintData:
            Depending on the chosen mode:
                Mode 1 -> Print all readings in binary (grouped by 4 bits)
                Mode 2 -> Print number of sensors ON and OFF per reading

    Main flow:
        - Ask user for number of readings (max 20).
        - Ask user for print mode (1 or 2).
        - Generate and display data accordingly.
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX_VALUE 65535 // 1111 1111 1111 1111
#define LEN 16 // 16 bits

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function declarations */
void GenerateSensorData(unsigned short data[], int count);
void PrintData(unsigned short data[], int count, int mode);
void printBinary(unsigned int number, int num_bits);

int main(void)
{
    int choice, readingAmount, displayMode;
    unsigned short data[20];

    srand(time(NULL));

    do
    {
        printf("--- Sensor Data Simulator ---\n");
        printf("1. Generate new data\n");
        printf("2. Exit.\n");
        printf("=> ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // generate new data
            printf("Enter number of readings (1-20): ");
            scanf("%d", &readingAmount);

            if (readingAmount < 1 || readingAmount > 20)
            {
                printf("Invalid count.\n");
                break;
            }

            GenerateSensorData(data, readingAmount);

            printf("Choose a display mode:\n");
            printf("1. Binary View\n");
            printf("2. Count ON Sensors\n");
            printf("=> ");

            scanf("%d", &displayMode);

            switch (displayMode)
            {
            case 1:
                PrintData(data, readingAmount, 1);
                break;
            case 2:
                PrintData(data, readingAmount, 2);
                break;
            default:
                printf("Please enter a valid option.\n");
                break;
            }
         
            break;
        case 2:
            printf("Bye bye!");
            break;
        default:
            printf("Please enter a valid option.\n");
            break;
        }

    } while (choice != 2);

    return 0;
}

/* function definitions */

void GenerateSensorData(unsigned short data[], int count)
{
    unsigned short leftBits;
    unsigned short rightBits;
    /*
    * - GenerateSensorData:
            Generates random sensor data for each entry in the array.
            Each reading (16 bits) should be filled using random bits (0 or 1).
            e.g.:
                reading 1 : 0111 0001 1111 0000
                reading 2 : 1100 0000 0000 0000

                [reading 1, reading 2, etc..., MAX_READINGS]
    */

    for (int i = 0; i < count; i++)
    {
        leftBits = rand() % 256;
        rightBits = rand() % 256;
        data[i] = (leftBits * 256) + rightBits;
    }
}

void PrintData(unsigned short data[], int count, int mode)
{
    /*
    * - PrintData:
            Depending on the chosen mode:
                Mode 1 -> Print all readings in binary (grouped by 4 bits)
                Mode 2 -> Print number of sensors ON and OFF per reading
    */

    switch (mode)
    {
    case 1: // binary view
        printf("\n");
        for (int i = 0; i < count; i++)
        {
            printf("Reading %2d: ", i + 1); // sensor reading

            printBinary(data[i], 16);
        }
        break;
    case 2: // Count ON Sensors
        break;
    default:
        break;
    }
}

void printBinary(unsigned int number, int bitAmount)
{
    int i, bit;

    for (i = bitAmount - 1; i >= 0; i--)
    {
        bit = (number >> i) & 1;
        printf("%d", bit);

        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}