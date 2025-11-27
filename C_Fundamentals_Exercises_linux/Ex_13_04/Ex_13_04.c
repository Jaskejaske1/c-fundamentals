#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define IS_CAPITAL(c) ((c >= 'A' && c <= 'Z'))
#define IS_SMALL(c) ((c >= 'a' && c <= 'z'))

int main() {
    char letter;

    printf("Geef een letter: ");
    scanf("%c%*c", &letter);

    printf("Is %c a hoofdletter? %d\n", letter, IS_CAPITAL(letter));
    printf("Is %c a kleine letter? %d\n\n", letter, IS_SMALL(letter));

    return 0;
}