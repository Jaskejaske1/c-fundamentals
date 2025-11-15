#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int, int);
int subtract(int, int);
int domath(int(*mathop)(int, int), int, int);
int domathSwitch(char, int, int);

int main(void)
{
	int a, b, c, d;


	// call domath function with add
	a = domath(add, 10, 2);
	printf("Add with function pointer gives: %d\n", a);

	// call domath function with subtract
	b = domath(subtract, 10, 2);
	printf("Subtract with function pointer gives: %d\n", b);

	//call domathSwitch with argument '+'
	c = domathSwitch('+', 10, 2);
	printf("Add with switch gives: %d\n", c);

	//call domathSwitch with argument '-'
	d = domathSwitch('-', 10, 2);
	printf("Subtract with switch gives: %d\n", d);

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

int domathSwitch(char opcode, int x, int y)
{
	int result;
	switch (opcode)
	{
	case '+': result = add(x, y);
		break;
	case '-': result = subtract(x, y);
		break;
	default:  result = add(x, y);
		break;
	}
	return result;
}