#include <stdio.h>
#include <string.h>

int main(void) {
    int nDice = 6;
    int faces = 6;
    int target = 33;

    // bounds-check
    if (target < nDice || target > nDice * faces) {
        printf("Aantal manieren (orde telt): 0\n");
        return 0;
    }

    // dp[s] = aantal manieren om som s te krijgen met de reeds verwerkte dobbelstenen
    unsigned long long dp[37] = { 0 }; // 6*6 = 36 max, dus 37 is genoeg
    dp[0] = 1;

    for (int d = 0; d < nDice; ++d) {
        unsigned long long ndp[37];
        memset(ndp, 0, sizeof ndp);
        for (int s = 0; s <= target; ++s) {
            if (dp[s] == 0) continue;
            for (int f = 1; f <= faces && s + f <= target; ++f) {
                ndp[s + f] += dp[s];
            }
        }
        memcpy(dp, ndp, sizeof dp);
    }

    printf("Aantal manieren (orde telt) om %d te gooien met %d dobbelstenen van %d zijden: %llu\n",
        target, nDice, faces, dp[target]);

    return 0;
}