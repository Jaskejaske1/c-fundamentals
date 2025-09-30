#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void lineair(float, float);
void vkv(float, float, float);
void tweereelewortels(float, float, float);
void eenwortel(float, float);
void complex(float, float, float);

int main(void)
{
    float a, b, c;



    printf("Oplossen van een vierkantsvergelijking\n");
    printf("Geef de coefficienten a, b en c ");

    scanf("%f%f%f%*c", &a, &b, &c);

    if (a)
        vkv(a, b, c);
    else
        lineair(b, c);

    return 0;
}



/*
    oplossen van de lineare vergelijking ax + b=0
*/
void lineair(float a, float b)
{
    if (a)
        printf("lineare vergelijking met wortel: %f\n", -b / a);
    else if (b)
        printf("Valse vergelijking\n");
    else
        printf("Identieke vergelijking\n");
}



/*
    oplossen van een "echte" vierkantsvergelijking
*/

void vkv(float a, float b, float c)
{
    float d;



    /* bereken discriminant */
    d = b * b - 4 * a * c;

    if (d > 0)
        tweereelewortels(a, b, d);
    else if (d == 0)
        eenwortel(a, b);
    else
        complex(a, b, d);
}



void tweereelewortels(float a, float b, float d)
{
    float wd, x1, x2;

    wd = (float)sqrt((double)d);

    x1 = (-b + wd) / (2 * a);
    x2 = (-b - wd) / (2 * a);

    printf("Twee reele wortels: %f en %f\n", x1, x2);
}



void eenwortel(float a, float b)
{
    printf("Een dubbele wortel %f\n", -b / (2 * a));
}



void complex(float a, float b, float d)
{
    /* i² = -1 */
    float re, im;

    re = -b / (2 * a);
    im = sqrt((double)(-d)) / (2 * a);

    printf("Twee complexe wortels: %f + %fi  en  %f - %fi\n", re, im, re, im);
}
