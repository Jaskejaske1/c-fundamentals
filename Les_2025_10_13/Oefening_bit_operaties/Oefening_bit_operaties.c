#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short number, shifted, masked;

	printf("Enter an integer [-32768, 32767]: ");
	scanf("%hd%*c", &number);

	printf("Integer in hex: %hx\n\n", number);

	for (int i = 15; i >= 0; i--)
	{
		shifted = number >> i;
		masked = shifted & 0x01;
		printf("%hd", masked);
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//short short_to_bin(short k);
//
//int main(void)
//{
//	short number;
//	short bin;
//
//	printf("Enter an integer [-32768, 32767]: ");
//
//	scanf("%hd%*c", &number);
//
//	bin = short_to_bin(number);
//
//	printf("%d", bin);
//
//	return 0;
//}
//
//short short_to_bin(short a)
//{
//	if (a == 0 || a == 1)
//	{
//		return a;
//	}
//	else
//	{
//		return ((a * 2) + 10 * short_to_bin(a / 2));
//	}
//}