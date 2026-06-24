/* LeetCode 202. Happy Number

A number is happy if repeatedly replacing it with the sum of the squares of its digits eventually reaches 1.

Example:

19

1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1 */

#include <stdio.h>
#include <stdbool.h>

int squareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int n = 19;

    if (isHappy(n))
        printf("Happy Number\n");
    else
        printf("Not Happy Number\n");

    return 0;
}