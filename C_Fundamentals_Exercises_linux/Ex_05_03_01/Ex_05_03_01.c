#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	for (number = -3; number <= 25; number += 2)
	{
		if (number == 25)
		{
			printf("%d", number);
		}
		else
		{
			printf("%d, ", number);
		}
	}

	printf("\n\n");

	return 0;
}