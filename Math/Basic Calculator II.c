/* LeetCode 227- Basic Calculator II

You need to evaluate an expression containing:

+
-
*
/
Spaces

No parentheses.

Idea

Use a stack.

For + → push number.
For - → push negative number.
For * → pop top, multiply, push result.
For / → pop top, divide, push result.

At the end, sum everything in the stack.*/
#include <ctype.h>
#include <stdio.h>

int main() {

    char s[] = "3+2*2";

    printf("%d\n", calculate(s));

    return 0;
}

int calculate(char *s) {
    int result = 0;
    int lastNum = 0;
    int num = 0;
    char sign = '+';

    for (int i = 0;; i++) {

        if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (sign == '+') {
                result += lastNum;
                lastNum = num;
            }
            else if (sign == '-') {
                result += lastNum;
                lastNum = -num;
            }
            else if (sign == '*') {
                lastNum *= num;
            }
            else if (sign == '/') {
                lastNum /= num;
            }

            sign = s[i];
            num = 0;
        }

        if (s[i] == '\0')
            break;
    }

    return result + lastNum;
}