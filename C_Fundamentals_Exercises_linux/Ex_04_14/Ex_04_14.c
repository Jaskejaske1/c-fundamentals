#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DECIMALEN 4

int main(void)
{
	/*
	 * ----(+ -)---( A )---- : spanningsbron en amperemeter
	 * |                   |
	 * |                   |
	 * ---[ R1 ]---[ R2 ]--- : weerstanden R1 en R2
	 */

	double bronspanning, R1, R2; // inputs
	double stroom, spanning_R2;

	printf("--~=<Wet van Ohm>=~--\n\n");

	// inputs inlezen
	printf("Geef de bronspanning (V): ");
	scanf("%lf%*c", &bronspanning);

	printf("Geef de weerstandswaarde van R1 (ohm): ");
	scanf("%lf%*c", &R1);

	printf("Geef de weerstandswaarde van R2 (ohm): ");
	scanf("%lf%*c", &R2);

	// berekeningen
	stroom = bronspanning / (R1 + R2);
	spanning_R2 = stroom * R2;

	// outputs
	printf("De stroom door het circuit is gelijk aan %.*lf A\n", DECIMALEN, stroom);
	printf("De spanning over R2 is gelijk aan %.*lf V\n\n", DECIMALEN, spanning_R2);

	return 0;
}