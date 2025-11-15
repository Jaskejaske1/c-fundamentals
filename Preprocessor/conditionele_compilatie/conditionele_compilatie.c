#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define UNIX
#undef UNIX

#ifdef UNIX
#define DATADIR "/uxn1/data"

#else
#define DATADIR "\usr\data"
#endif

int main(void)
{

	return 0;
}