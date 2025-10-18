/*
 * Prints Pascal's Triangle
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // Max dimension of the triangle
#define MAX_DIMENSION 20
// Width for each number to ensure proper alignment
#define NUM_WIDTH 5 

// Function Prototypes
int read_dimension(void);
void make_triangle(int a[][MAX_DIMENSION], int n);
void print_triangle(int a[][MAX_DIMENSION], int n);


int main(void)
{
	// Rename array 'a' to 'pascal_triangle' for clarity
	int pascal_triangle[MAX_DIMENSION][MAX_DIMENSION];
	// Rename 'n' to 'dimension'
	int dimension;

	printf("Pascal's Triangle\n");

	// Call refactored function
	dimension = read_dimension();
	make_triangle(pascal_triangle, dimension);
	print_triangle(pascal_triangle, dimension);

	return 0;
}

// Function to read the triangle's dimension from the user
int read_dimension(void)
{
	int d;

	do
	{
		printf("Enter dimension (in [0 .. %2d[): ", MAX_DIMENSION);
		// Note: The original format %*c is kept to consume the newline character
		if (scanf("%d%*c", &d) != 1) {
			// Handle non-integer input to prevent infinite loop
			while (getchar() != '\n');
			d = -1; // Force loop restart
		}
	} while (d < 0 || d >= MAX_DIMENSION);

	return d;
}


// Function to calculate and fill Pascal's Triangle
void make_triangle(int a[][MAX_DIMENSION], int n)
{
	int i, j;

	// Base case: a[0][0] = 1
	a[0][0] = 1;

	// Set edges (all 1s)
	for (i = 1; i <= n; ++i)
	{
		a[i][0] = 1; // Left edge
		a[i][i] = 1; // Right edge
	}

	// Calculate inner values: a[i][j] = a[i-1][j-1] + a[i-1][j]
	for (i = 2; i <= n; ++i)
	{
		for (j = 1; j < i; ++j)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

// Function to print the triangle in an equilateral (centered) format
void print_triangle(int a[][MAX_DIMENSION], int n)
{
	int i, j, k;

	for (i = 0; i <= n; ++i)
	{
		// 1. Calculate and print the initial spacing for centering
		// Space needed is proportional to the number of rows remaining (n - i).
		// Each space unit is half the width of a number.
		for (k = 0; k < (n - i) * NUM_WIDTH / 2; ++k)
		{
			printf(" ");
		}

		// 2. Print the row's elements
		for (j = 0; j <= i; ++j)
		{
			// Print number with constant width for alignment
			printf("%*d", NUM_WIDTH, a[i][j]);
		}

		printf("\n");
	}
}