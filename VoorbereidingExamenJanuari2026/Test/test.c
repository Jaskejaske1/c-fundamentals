#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* p;
    // CORRECT: We reserveren 45 bytes (5 blokken van 9)
    p = (char*)malloc(5 * 9 * sizeof(char));

    for (int i = 0; i < 5; i++) {

        // CORRECTIE: We moeten stappen van 9 nemen!
        // String 0 begint op 0
        // String 1 begint op 9
        // String 2 begint op 18
        int start = i * 9;

        // Vul 8 sterretjes
        for (int j = 0; j < 8; j++) {
            p[start + j] = '*';
        }

        // Zet de null-terminator op de 9e plek (index 8)
        p[start + 8] = '\0';
    }

    // Test (optioneel, om te zien dat het werkt)
    // for(int i=0; i<5; i++) printf("%s\n", &p[i*9]);

    free(p); // Vergeet niet vrij te geven!
    return 0;
}