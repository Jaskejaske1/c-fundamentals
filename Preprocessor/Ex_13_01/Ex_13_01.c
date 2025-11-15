#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b)) // haakjes niet vergeten, ookal denk je dat het niet nodig is!

int main(void)
{
	int a, b, min;
	printf("Enter 2 integer numbers: ");
	(void)scanf("%d%d%*c", &a, &b);

	min = MIN(a, b);

	printf("The minimum of %d and %d = %d\n", a, b, min);

	min = MIN(a + b, a - b);

	printf("The minimum of %d and %d = %d\n", a + b, a - b, min);
	return 0;
}