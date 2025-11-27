/* fwrite example : write buffer */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BESTAND "myfile.bin"

int main(void)
{
	FILE* pFile;
	float buffer[3] = { 1.0 , 11.5 , 48.45 };

	pFile = fopen(BESTAND, "wb");
	if (pFile == NULL)
	{
		printf("Het bestand %s is niet te openen\n", BESTAND);
		exit(1);
	}

	fwrite(buffer, sizeof(float), 3, pFile);
	fclose(pFile);

	return 0;
}