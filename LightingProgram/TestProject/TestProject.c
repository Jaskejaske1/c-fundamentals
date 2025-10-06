#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LIGHTS_AMOUNT 8

void print_lights(char[], int);

int main(void)
{
	char lightOn = 178;
	char lightOff = 176;
	char lights[LIGHTS_AMOUNT];
	
	for (int i = 0; i < LIGHTS_AMOUNT; i++)
	{
		lights[i] = lightOn;
	}

	print_lights(lights, LIGHTS_AMOUNT);

	return 0;
}

void print_lights(char lights[], int lights_amount)
{
	for (int i = 0; i < lights_amount; i++)
	{
		printf("%c ", lights[i]);
	}
	printf("\n");
}