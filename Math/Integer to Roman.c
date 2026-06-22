// Leetcode 12- Integer to Roman

#include <stdio.h>
#include <string.h>

char* intToRoman(int num);

int main() {
    int num;
    scanf("%d", &num);

    printf("%s\n", intToRoman(num));

    return 0;
}
char* intToRoman(int num) {
    static char result[20];

    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    result[0] = '\0';

    for(int i = 0; i < 13; i++) {
        while(num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}