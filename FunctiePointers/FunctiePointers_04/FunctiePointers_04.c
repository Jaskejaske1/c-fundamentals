#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int, int);
int substract(int, int);
int (*choose(void))(int, int);

int main(void)
{
	int(*fptr)(int, int);

	fptr = choose();

	printf("The result of this operation is: %d\n", (*fptr)(10, 2));

	return 0;
}

// add x + y
int add(int x, int y) {
	return x + y;
}

// subtract x - y
int substract(int x, int y) {
	return x - y;
}

// run the function pointer with inputs
int(*choose(void))(int, int)
{
	int choise;
	do
	{
		printf("What do you choose:\n1\taddition\n2\tsubtraction\n\n");
		(void)scanf("%d%*c", &choise);
	} while (choise < 1 || choise > 2);

	switch (choise)
	{
	case 1: return add;
	case 2: return substract;
	}
}