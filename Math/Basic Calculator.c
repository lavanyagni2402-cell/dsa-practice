#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[100000];
    int top = -1;

    int num = 0;
    char sign = '+';

    for (int i = 0; ; i++) {

        if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (sign == '+')
                stack[++top] = num;

            else if (sign == '-')
                stack[++top] = -num;

            else if (sign == '*')
                stack[top] *= num;

            else if (sign == '/')
                stack[top] /= num;

            sign = s[i];
            num = 0;
        }

        if (s[i] == '\0')
            break;
    }

    int ans = 0;

    while (top >= 0)
        ans += stack[top--];

    return ans;
}