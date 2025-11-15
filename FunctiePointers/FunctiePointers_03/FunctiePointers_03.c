#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int, int);
int subtract(int, int);
int domath(int(*mathop)(int, int), int, int);

int main(void)
{
	int a, b, c, d;

	// array van functie pointers
	// 1 int als return waarde, 2 integers als argumenten
	int(*fptr[2])(int, int) = { add, subtract };


	// call domath function with add
	a = domath(fptr[0], 10, 2);
	printf("Add with function pointer gives: %d\n", a);

	// call domath function with subtract
	b = domath(fptr[1], 10, 2);
	printf("Subtract with function pointer gives: %d\n", b);

	return 0;
}

// add x + y
int add(int x, int y)
{
	return x + y;
}

// subtract x - y
int subtract(int x, int y)
{
	return x - y;
}

// run the function pointer with inputs
int domath(int(*mathop)(int, int), int x, int y)
{
	return (*mathop)(x, y);
}