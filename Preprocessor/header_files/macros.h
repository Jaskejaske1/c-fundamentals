#pragma once

#ifdef MACRO_H
// Do nothing
#else
#define MACRO_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#ifndef PI
#define PI 3.14159265358979 // Constant
#endif

#ifndef MAXIMUM
#define MAXIMUM 50 // Maximum constant
#endif

#ifndef SIZE
#define SIZE 10 // The size of an array for example
#endif

#ifndef EQ
#define EQ == // If you forget the double == in if's, you can write EQ
#endif

#define DEBUG 1 // Easy debugging, switch of, by setting DEBUG to 0.

/*#ifndef TEST
#endif*/
#define CUBE(a) a*a*a // UNSAFE Macro, do not forget ( )
#define CUBE1(a) (a)*(a)*(a)

#define MAX2(a,b) (a>b ? a : b) // Short if function.
#define MAX3(a,b,c) (MAX2((MAX2(a,b)),c)) // Use Macro for short functions.

#define MAX2A(a,b) (if (a>b){\
puts("a is greater than b"); \
}\
else{\
puts("b is greater than a"); \
})

// Use \ to split over the lines, AVOID USING THIS

#define MESSAGE(from,to) printf(#from " gives a message to " #to "\n") // To concatenate strings.

//#define HP2510

#if defined(HP2510) || defined(HP2780) || defined(HP2770)   // Machine specific code.
#define HP
#else
#define OTHER
#endif

#undef OTHER  // You can also undefine a constant.

#define FILE_NAME(file) puts("HP_"##file)
#endif