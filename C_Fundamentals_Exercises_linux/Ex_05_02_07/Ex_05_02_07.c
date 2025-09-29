#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float userSpeed, speedLimit, speedDifference, fine;

	printf("Be aware! Speeding is heavily fined!\n");

	printf("Enter your speed: ");

	if (scanf("%f%*c", &userSpeed) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Enter the speed limit: ");
	if (scanf("%f%*c", &speedLimit) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	if (userSpeed > speedLimit)
	{
		speedDifference = userSpeed - speedLimit;
		printf("Your speed is %.2f km/h over the speed limit.\n", speedDifference);
		fine = 100 + 2.5 * (speedDifference);
		printf("Your fine amounts %.1f euro.\n", fine);
	}

	printf("\n");

	return 0;
}