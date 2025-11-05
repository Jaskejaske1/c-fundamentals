// msvc_string_safe_demo.c
// Demonstrates MSVC-specific string helpers and secure input/output

#define _CRT_SECURE_NO_WARNINGS  // optional: silence "unsafe" warnings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 100

int main(void)
{
    char str[BUF];
    char copy[BUF];

    // --- SAFE INPUT ---
    printf("Enter text: ");
    fgets(str, BUF, stdin);
    str[strcspn(str, "\n")] = '\0';   // remove newline

    // Alternatively:
    // scanf_s("%99s", str, (unsigned)_countof(str));

    // --- STRING OPERATIONS ---

    // Duplicate using _strdup (MSVC extension)
    char* dup = _strdup(str);

    // Make a copy safely
    strcpy_s(copy, BUF, str);

    // Uppercase
    _strupr(copy);

    // Lowercase the duplicate
    _strlwr(dup);

    // Reverse original string in place
    _strrev(str);

    // Display results
    printf("\n--- Results ---\n");
    printf("Original reversed: %s\n", str);
    printf("Uppercase copy:   %s\n", copy);
    printf("Lowercase dup:    %s\n", dup);

    // Fill a string section
    char fill[BUF] = "HELLO WORLD";
    _strnset(fill, '*', 5);    // *****
    printf("Star-filled:      %s\n", fill);

    // Cleanup
    free(dup);

    return 0;
}
