/*
Tabel met cosinuswaarden
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int hoek;
	double rad, cosinus;

	printf("  hoek\t|  cos\n");
	printf("----------------\n");

	for (hoek = 0; hoek <= 360; hoek += 30)
	{
		rad = M_PI / 180 * hoek;
		cosinus = cos(rad);
		printf(" %3d\t| %5.2lf\n", hoek, cosinus);
	}

	return 0;
}