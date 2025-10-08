/*
	sorting an array of integer numbers
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int ReadSize(void);
void ReadArray(int[], int);
void SortArray(int[], int);
void PrintArray(int[], int);

int main(void)
{
	int row[MAX_SIZE];
	int size;

	printf("Sorting a list of integers\n");

	// read number of integers that will be entered
	size = ReadSize();

	// read integers
	ReadArray(row, size);

	// order row
	SortArray(row, size);

	// print ordered row
	PrintArray(row, size);

	return 0;
}

int ReadSize(void)
{
	int n;

	do
	{
		printf("Enter the number of integers you want to sort: [1.. % d] ", MAX_SIZE);
		scanf("%d%*c", &n);
	} while (n < 1 || n > MAX_SIZE);

	return n;
}


void ReadArray(int a[], int n)
{
	int i;

	printf("Enter %d integers:\n", n);

	for (i = 0; i < n; ++i)
		scanf("%d%*c", &a[i]);
}

void SortArray(int a[], int n)
{
	int i, j, hulp;
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				hulp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hulp;
			}
		}
	}
}

void PrintArray(int a[], int n)
{
	int i;

	printf("The ordered row:\n");

	for (i = 0; i < n; i++)
	{
		printf("%8d", a[i]);
	}
	printf("\n");
}