/*
Write the function print_string to finalize the next program.
The function print_string prints a string, received as argument,
character by character using the function putchar().
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#define MAXSTRING 100 

void print_string(char* c);

int main(void)
{
    char s1[MAXSTRING], s2[MAXSTRING];

    strcpy(s1, "Mary, Mary, quite contrary.\n");
    strcpy(s2, "How does your garden grow ? \n");

    print_string(s1);
    print_string(s2);
    strcat(s1, s2);
    print_string(s1);
    return 0;
}

void print_string(char* c)
{
    int len, i;
    len = strlen(c);

    for (i = 0; i < len; i++)
    {
        putchar(c[i]);
    }
}