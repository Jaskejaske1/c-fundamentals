#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

void readArray(int[]);
void printArrays(int[], int[]);

int main(void)
{
	int array1[SIZE], array2[SIZE];

	readArray(array1);
	readArray(array2);

	printArrays(array1, array2);

	return 0;
}

void readArray(int arr[])
{
	int getal;
	printf("Geef het eerrste getal van de array: ");
	(void)scanf("%d%*c", &arr[0]);
	for (int i = 1; i < SIZE; i++)
	{
		do
		{
			printf("Geef een getal groter dan het vorige: ");
			(void)scanf("%d%*c", &getal);
		} while (getal < arr[i - 1]);
		arr[i] = getal;
	}

}

void printArrays(int arr1[], int arr2[])
{
	int index1 = 0, index2 = 0;

	while (index1 < SIZE && index2 < SIZE)
	{
		if (arr1[index1] < arr2[index2])
		{
			printf("%d\t", arr1[index1]);
			index1++;
		}
		else
		{
			printf("%d\t", arr2[index2]);
			index2++;
		}
	}

	while (index1 < SIZE)
	{
		printf("%d\t", arr1[index1]);
		index1++;
	}

	while (index2 < SIZE)
	{
		printf("%d\t", arr2[index2]);
		index2++;
	}
}