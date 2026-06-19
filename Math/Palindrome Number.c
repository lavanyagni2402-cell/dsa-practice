#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    long rev = 0;
    int original = x;

    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return original == rev;
}

int main() {
    int x = 121;

    if (isPalindrome(x))
        printf("true\n");
    else
        printf("false\n");

    return 0;////
}