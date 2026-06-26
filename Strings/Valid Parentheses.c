#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isValid(char* s);

int main() {
    char s[] = "()[]{}";

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            if (top == -1)
                return false;

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
                return false;
        }
    }

    return top == -1;
}