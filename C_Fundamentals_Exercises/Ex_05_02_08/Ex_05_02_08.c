#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double height, weight, BMI;
	printf("BMI Calculator\n");

	printf("Please enter your height in meters: ");
	if (scanf("%lf%*c", &height) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	printf("Please enter your weight in kilograms: ");
	if (scanf("%lf%*c", &weight) != 1)
	{
		printf("Invalid input.\n\n");
		return 1;
	}

	BMI = weight / (height * height);
	printf("BMI = %lf\n", BMI);

	if (BMI < 18.5)
	{
		printf("You are underweight.\n\n");
	}
	else if (BMI >= 18.5 && BMI < 25)
	{
		printf("You have a normal weight.\n\n");
	}
	else if (BMI >= 25 && BMI < 30)
	{
		printf("You are overweigt.\n\n");
	}
	else if (BMI >= 30)
	{
		printf("You are obese.\n\n");
	}
	else
	{
		printf("Something went wrong, try again.\n\n");
		return 1;
	}

	return 0;
}