/* For LeetCode 44. Wildcard Matching, the optimal approach is Dynamic Programming.

Idea
? matches exactly one character.
* matches any sequence of characters (including empty).

Let dp[i][j] = whether s[0...i-1] matches p[0...j-1].

Transitions

If characters match or pattern has ?:

dp[i][j] = dp[i-1][j-1]

If pattern has *:

dp[i][j] = dp[i][j-1] || dp[i-1][j]
dp[i][j-1] → * matches empty string.
dp[i-1][j] → * matches one more character. */

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool **dp = (bool **)malloc((m + 1) * sizeof(bool *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (bool *)calloc(n + 1, sizeof(bool));
    }

    dp[0][0] = true;

    // Empty string with leading '*'
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    bool ans = dp[m][n];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}