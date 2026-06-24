/* LeetCode 96. Unique Binary Search Trees

This is a classic Catalan Number problem.

Let dp[i] = number of unique BSTs that can be formed using i nodes.

For each root j:

left subtree  = j - 1 nodes
right subtree = i - j nodes

dp[i] += dp[j-1] * dp[i-j] */
#include <stdio.h>

int numTrees(int n) {
    int dp[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;

        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int main() {
    int n = 3;

    printf("%d\n", numTrees(n));

    return 0;
}
