#include <limits.h>
#include <stdlib.h>
#include <string.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize) {

    int *dp = (int *)malloc((stoneValueSize + 3) * sizeof(int));

    for (int i = 0; i < stoneValueSize + 3; i++)
        dp[i] = 0;

    for (int i = stoneValueSize - 1; i >= 0; i--) {

        int best = INT_MIN;
        int sum = 0;

        for (int k = 0; k < 3 && i + k < stoneValueSize; k++) {

            sum += stoneValue[i + k];

            if (sum - dp[i + k + 1] > best)
                best = sum - dp[i + k + 1];
        }

        dp[i] = best;
    }

    int result = dp[0];
    free(dp);

    if (result > 0)
        return "Alice";
    else if (result < 0)
        return "Bob";
    else
        return "Tie";
}