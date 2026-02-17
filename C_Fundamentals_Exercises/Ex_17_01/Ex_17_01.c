#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void readArray(int** matrix, int dim);
void calculate(int** matrix, int dim, int* sumMain, int* sumAnti, int* maxVal);

int main() {
    int dim;
    int sumMain, sumAnti, maxVal;

    // 1. Get Dimension
    printf("What is the matrix dimension? ");
    if (scanf("%d", &dim) != 1 || dim <= 0) {
        printf("Invalid dimension.\n");
        return 1;
    }

    // 2. Allocate Memory (The "Double Pointer" method)
    int** matrix = (int**)malloc(dim * sizeof(int*));
    if (matrix == NULL) return 1;

    for (int i = 0; i < dim; i++) {
        matrix[i] = (int*)malloc(dim * sizeof(int));
        if (matrix[i] == NULL) return 1; // Simple error handling
    }

    // 3. Read Input
    printf("Enter the matrix\n");
    readArray(matrix, dim);

    // 4. Calculate
    calculate(matrix, dim, &sumMain, &sumAnti, &maxVal);

    // 5. Print Results
    printf("\nThe diagonal top left to bottom right sums up to %d\n", sumMain);
    printf("The diagonal bottom left to top right sums up to %d\n", sumAnti);
    printf("The maximum number in the matrix is %d\n", maxVal);

    // 6. Free Memory
    for (int i = 0; i < dim; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to read matrix content
void readArray(int** matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to calculate sums and find max
void calculate(int** matrix, int dim, int* sumMain, int* sumAnti, int* maxVal) {
    *sumMain = 0;
    *sumAnti = 0;
    *maxVal = matrix[0][0]; // Initialize max to the first element

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {

            // Logic for Maximum
            if (matrix[i][j] > *maxVal) {
                *maxVal = matrix[i][j];
            }

            // Logic for Main Diagonal (Top-Left to Bottom-Right)
            if (i == j) {
                *sumMain += matrix[i][j];
            }

            // Logic for Anti-Diagonal (Bottom-Left to Top-Right)
            // Indices sum to dimension - 1 (e.g., in 3x3: (2,0), (1,1), (0,2))
            if (i + j == dim - 1) {
                *sumAnti += matrix[i][j];
            }
        }
    }
}