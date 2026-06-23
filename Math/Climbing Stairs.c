/*Leetcode 70- Climbing Stairs
Idea

If you're on stair n, the last move could be:

1 step from n-1
2 steps from n-2

So:

dp[n]=dp[n−1]+dp[n−2]

This is exactly the Fibonacci pattern.*/

#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2)
        return n;

    int a = 1, b = 2, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    printf("Enter number of stairs: ");
    scanf("%d", &n);

    printf("Number of ways = %d\n", climbStairs(n));

    return 0;
}