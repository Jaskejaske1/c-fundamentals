#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short getal;

	printf("Geef een geheel getal uit het interval[-32768,32767]: ");
	scanf("%hd%*c", &getal);

	printf("Het ingegeven getal is:\ndec: %hd\nhex: %x.\n\n", getal, getal);

	getal = getal >> 12;	//12 bits opschuiven zodat 4 MSB's nu 4 LSB's worden

	printf("Het getal is nu:\ndec: %hd of hex: %x.\n\n", getal, getal);

	getal = getal & 0x000f;		//masking om leading 1-en bij een negatief getal te verwijderen

	printf("De hoogste nibble is:\ndec: %hd of hex: %x.\n\n", getal, getal);

	return 0;
}
