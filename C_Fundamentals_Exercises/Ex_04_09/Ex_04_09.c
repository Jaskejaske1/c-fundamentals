#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592653589793

int main(void)
{
	double radius, area;

	printf("Enter the radius of a circle: ");
	scanf("%lf%*c", &radius);

	area = radius * radius * PI;

	printf("The surface area of a circle with radius %lf is %lf.\n\n", radius, area);
	return 0;
}