#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_DIM 10

int readDimension(void);
void readMatrix(int matrix[][MAX_DIM], int dim);
void transposeMatrix(int matrix[][MAX_DIM], int tMatrix[][MAX_DIM], int dim);
void printMatrix(int matrix[][MAX_DIM], int dim);

int main(void)
{
	int dim, matrix[MAX_DIM][MAX_DIM], tMatrix[MAX_DIM][MAX_DIM];

	dim = readDimension();
	readMatrix(matrix, dim);
	transposeMatrix(matrix, tMatrix, dim);

	printf("\nDimensions are: %dx%d\n", dim, dim);

	printf("\nOriginal matrix:\n");
	printMatrix(matrix, dim);

	printf("\nTransposed matrix:\n");
	printMatrix(tMatrix, dim);

	return 0;
}

int readDimension(void)
{
	int dim;
	printf("Please enter a dimension for the square matrix: ");
	if (scanf("%d%*c", &dim) != 1)
	{
		printf("Invalid input.\n\n");
		exit(EXIT_FAILURE);
	}
	return dim;
}

void readMatrix(int matrix[][MAX_DIM], int dim)
{
	int currentElement;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf("Enter a value for row %d and column %d: ", i + 1, j + 1);
			(void)scanf("%d%*c", &currentElement);
			matrix[i][j] = currentElement;
		}
	}
}

void transposeMatrix(int matrix[][MAX_DIM], int tMatrix[][MAX_DIM], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			tMatrix[i][j] = matrix[j][i];
		}
	}
}

void printMatrix(int matrix[][MAX_DIM], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
