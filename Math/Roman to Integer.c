// Leetcode 13-  Roman to Integer

#include <stdio.h>

int value(char c);
int romanToInt(char* s);

int main() {
    char s[20];

    scanf("%s", s);

    printf("%d\n", romanToInt(s));

    return 0;
}

int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char* s) {
    int sum = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        int curr = value(s[i]);
        int next = value(s[i + 1]);

        if(curr < next)
            sum -= curr;
        else
            sum += curr;
    }

    return sum;
}