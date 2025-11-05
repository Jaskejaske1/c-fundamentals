#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char binStr[33];     // Up to 32 bits + '\0'
    int bits[32];        // 32 integers for binary digits

    printf("Enter a number: ");
    scanf("%d", &num);

    _itoa(num, binStr, 2);   // base 2 = binary
    printf("Binary string: %s\n", binStr);  // e.g. "1101"

    int len = strlen(binStr);

    // ----- CHAR ARRAY -> INT ARRAY (0/1) -----
    for (int i = 0; i < len; i++)
    {
        bits[i] = binStr[i] - '0';   // '1' -> 1, '0' -> 0
    }

    printf("Binary digits: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", bits[i]);
    }
    printf("\n");

    // ----- BITSHIFT METHOD (official computer-science way) -----
    printf("Bitshift view (32 bits): ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);   // extract bit i
    }
    printf("\n");

    return 0;
}
