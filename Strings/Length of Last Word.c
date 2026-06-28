#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char* s);

int main() {
    char s[] = "Hello World";

    printf("%d\n", lengthOfLastWord(s));

    return 0;
}
int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;

    while (i >= 0 && s[i] == ' ')
        i--;

    int length = 0;
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
