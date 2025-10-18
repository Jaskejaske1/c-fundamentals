#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RIJEN 3
#define KOLOMMEN 5

void CreateMatrix(int[][KOLOMMEN]);
void PrintMatrix(int[][KOLOMMEN]);

int main(void)
{
	int matrix[RIJEN][KOLOMMEN];

	CreateMatrix(matrix);
	PrintMatrix(matrix);

	return 0;
}

void CreateMatrix(int matrix[][KOLOMMEN])
{
	for (int rij = 0; rij < RIJEN; rij++)
	{
		for (int kolom = 0; kolom < KOLOMMEN; kolom++)
		{
			matrix[rij][kolom] = kolom + 10 * rij;
		}
	}
}

void PrintMatrix(int matrix[][KOLOMMEN])
{
	printf("+----+----+----+----+----+\n");
	for (int rij = 0; rij < RIJEN; rij++)
	{
		for (int kolom = 0; kolom < KOLOMMEN; kolom++)
		{
			printf("| %-3d", matrix[rij][kolom]);
		}
		printf("|\n");
	}
	printf("+----+----+----+----+----+\n");
}