/*
leesGetallen.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define BESTAND "../voorbeeld8_tekstbestand_schrijven/getallen.txt"

int main(void)
{
	FILE* fp;
	int getal;

	fp = fopen(BESTAND, "r");

	if (fp == NULL)
	{
		printf("het bestand %s is niet te openen\n", BESTAND);
		exit(-1);
	}

	while (fscanf(fp, "%d%*c", &getal) > 0)
	{
		printf("%d ", getal);
	}

	fclose(fp);
	printf("\n");

	return 0;
}
