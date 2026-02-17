#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int aantal, som = 0;
    int* lijst = NULL;
    float avg = 0.0f;

    printf("Hoeveel getallen wil je ingeven?: ");
    scanf("%d%*c", &aantal);

    if (aantal <= 0) {
        printf("Ongeldig aantal!\n");
        return 1;
    }

    lijst = malloc(aantal * sizeof(*lijst));
    if (!lijst) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < aantal; i++) {
        printf("Geef getal %d: ", i + 1);
        scanf("%d%*c", &lijst[i]);
        som += lijst[i];
    }

    avg = (float)som / aantal;

    printf("\nDe som is %d en het gemiddelde is %.2f\n", som, avg);
    printf("Omgekeerde volgorde: ");
    for (int i = aantal - 1; i >= 0; i--) {
        printf("%d ", lijst[i]);
    }

    free(lijst);
    return 0;
}
