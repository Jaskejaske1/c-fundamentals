#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 32
#define FILEPATH "voorraad.dat"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int productID;
	char naam[MAX_LEN];
	float prijs;
	int voorraad;
} Product;

int main(void)
{
	FILE* fp;
	Product temp;

	fp = fopen(FILEPATH, "rb+");
	if (fp == NULL)
	{
		perror("Cannot open file!\n");
		exit(EXIT_FAILURE);
	}

	// update de prijs van het 10e product
	fseek(fp, 9 * sizeof(Product), SEEK_SET);
	fread(&temp, sizeof(Product), 1, fp);
	temp.prijs = 24.99f;
	fseek(fp, -1L * sizeof(Product), SEEK_CUR);
	fwrite(&temp, sizeof(Product), 1, fp);
	fclose(fp);
	fp = NULL;
	return 0;
}