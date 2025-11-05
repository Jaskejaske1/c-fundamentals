#define _CRT_SECURE_NO_WARNINGS

// C program to demonstrate
// example of strrev() function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 128

int main()
{
    char str[LENGTH];

    printf("Please enter a palindrome: ");

    fgets(str, LENGTH, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Is %s palindrome?: %s\n", str, isPalindrome(str) ? "yes" : "no");

    return 0;
}

int isPalindrome(char str[])
{
    char revstr[LENGTH];
    strcpy(revstr, str);

    _strrev(revstr);

    if (strcmp(revstr, str))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}