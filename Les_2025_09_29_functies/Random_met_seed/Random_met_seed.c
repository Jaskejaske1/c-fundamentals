/*
Genereer 10 random getallen tussen 1 en 100
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

int main(void)
{
	int i;
	long tijd;

	tijd = time(NULL);

	srand(tijd);

	for (i = 0; i < 10; i++)
		printf("%4d\n", 1 + rand() % 100);

	return 0;
}
