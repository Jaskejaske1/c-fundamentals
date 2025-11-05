/*
    -----------------------------------------------------------
    Exercise 2: Randomized LED Pattern Controller
    -----------------------------------------------------------

    Class: 1EICT
    Name: Savels
    Firstname: Jasper

    Goal:
    Simulate an LED panel with 8 LEDs using bit operations.
    The LEDs can be randomly turned ON/OFF and shifted left/right.

    Requirements:
    - Use arrays, for-loops, while-loops, if-statements, switch-statements.
    - Use bit shifting (<<, >>) for LED movement.
    - Use srand() and rand() for random LED initialization.
    - Use precompiler directives for constants. ( #define )
    - Use the following libraries:
        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

    Function Signatures:
        void InitLEDs(unsigned char leds[], int count);
        void ShiftLEDs(unsigned char leds[], int count, int direction);
        void DisplayLEDs(unsigned char leds[], int count);

    Functionality:
        - InitLEDs:
            Initializes each byte with random ON/OFF bits.
        - ShiftLEDs:
            Shifts all LEDs in chosen direction:
                0 -> shift left
                1 -> shift right
        - DisplayLEDs:
            Prints LEDs as binary and visually using '*' for ON and '.' for OFF.

    Main flow:
        - Initialize LEDs.
        - Ask the user to repeatedly choose:
            1. Shift left
            2. Shift right
            3. Randomize again
            4. Quit
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define COUNT 8

/* function declarations */

void InitLEDs(unsigned char leds[], int count);
void ShiftLEDs(unsigned char leds[], int count, int direction);
void DisplayLEDs(unsigned char leds[], int count);
void printBits(unsigned char num, char on, char off);

int main(void)
{
    unsigned char leds[COUNT];
    int choice;

    srand(time(NULL));
    InitLEDs(leds, COUNT);

    do
    {
        DisplayLEDs(leds, COUNT);

        printf("\n--- LED Controller ---\n");
        printf("1. Shift Left\n");
        printf("2. Shift Right\n");
        printf("3. Randomize LEDS\n");
        printf("4. Quit\n");
        printf("=> ");

        if (scanf("%d%*c", &choice) != 1)
        {
            printf("Error reading input. Please try again.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice)
        {
        case 1:
            ShiftLEDs(leds, COUNT, 0);
            break;
        case 2:
            ShiftLEDs(leds, COUNT, 1);
            break;
        case 3:
            InitLEDs(leds, COUNT);
            break;
        case 4:
            printf("Quitting, bye!\n");
            break;
        default:
            printf("Please choose a valid option.\n");
            break;
        }

    } while (choice != 4);

    return 0;
}

/* function definitions */

void InitLEDs(unsigned char leds[], int count)
{
    for (int i = 0; i < count; i++)
    {
        leds[i] = rand() % 256;
    }
}

void ShiftLEDs(unsigned char leds[], int count, int direction)
{
    /*
    * Shifts all LEDs in chosen direction:
                0 -> shift left
                1 -> shift right
    */

    if (direction == 0)
    {
        for (int i = 0; i < count; i++)
        {
            leds[i] = leds[i] << 1;
        }
    }
    else if (direction == 1)
    {
        for (int i = 0; i < count; i++)
        {
            leds[i] = leds[i] >> 1;
        }
    }
}

void DisplayLEDs(unsigned char leds[], int count)
{
    printf("Current LED States:\n");
    for (int i = 0; i < count; i++)
    {
        printf("LED Row %d: ", i + 1);
        printBits(leds[i], '*', '.');
        printf("  (");
        printBits(leds[i], '1', '0');
        printf(")\n");
    }
}

void printBits(unsigned char num, char on, char off)
{
    for (int i = 7; i >= 0; i--) {
        if (num & (1 << i))
            printf("%c", on);
        else
            printf("%c", off);
    }
}
