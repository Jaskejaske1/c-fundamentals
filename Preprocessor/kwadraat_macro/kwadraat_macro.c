// #define KWADRAAT(x) x * x
#define KWADRAAT(x) ((x) * (x)) // HAAKJES ZIJN HEEL ERG BELANGRIJK!!
#include <stdio.h>

int main(void)
{
	int x, a = 2, b = 3;
	x = KWADRAAT(a + b);
	printf("kwadraat van %d = %d", a + b, x);
	return 0;
}