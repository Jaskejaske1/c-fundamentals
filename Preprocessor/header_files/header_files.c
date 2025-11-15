#include "macros.h"

int main(void)
{
	int r;
	int result;
	int result1;

	r = 2;
	result = 0;
	result1 = 0;

	FILE_NAME("1234");

	if (DEBUG == 1)
	{
		r = 20;
		printf("The result in the beginning is : %d\n", result);
	}

	printf("The result of pi * (r ^ 2) = %f\n", PI * (r * r));

	if (MAXIMUM EQ 50)
	{
		result = CUBE(r + 5);// test also with expression r+5
		if (DEBUG == 1) // I could use EQ instead of ==
		{
			printf(" Result QUBE : %d\n", result);
		}
		result1 = CUBE1(r + 5); // test also with expression r+5
		printf(" Result QUBE : %d\n", result1);

		puts("Maximum is achieved");

	}
	else
	{
		puts("You should achieve the maximum value");
	}

	MESSAGE(Sofie, you);
}