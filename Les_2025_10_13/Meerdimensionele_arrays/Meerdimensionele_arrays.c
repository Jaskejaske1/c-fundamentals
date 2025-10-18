#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RIJEN 3
#define KOLOMMEN 5

int main(void)
{
	int matrix[RIJEN][KOLOMMEN];
	int rij, kolom;

	for (rij = 0; rij < RIJEN; rij++)
	{
		for (kolom = 0; kolom < KOLOMMEN; kolom++)
		{
			matrix[rij][kolom] = kolom + 10 * rij;
		}
	}

	printf("+----+----+----+----+----+\n");
	for (rij = 0; rij < RIJEN; rij++)
	{
		for (kolom = 0; kolom < KOLOMMEN; kolom++)
		{
			printf("| %-3d", matrix[rij][kolom]);
		}
		printf("|");
		printf("\n");
	}
	printf("+----+----+----+----+----+\n");

	return 0;
}