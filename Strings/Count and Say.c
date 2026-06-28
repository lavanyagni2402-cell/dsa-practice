#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {

    int n = 5;

    char *ans = countAndSay(n);

    printf("%s\n", ans);

    free(ans);

    return 0;
}

char* countAndSay(int n) {

    char *current = (char*)malloc(5000);
    strcpy(current, "1");

    for (int i = 2; i <= n; i++) {

        char *next = (char*)malloc(5000);
        next[0] = '\0';

        int len = strlen(current);

        for (int j = 0; j < len;) {

            char digit = current[j];
            int count = 0;

            while (j < len && current[j] == digit) {
                count++;
                j++;
            }

            char temp[20];
            sprintf(temp, "%d%c", count, digit);

            strcat(next, temp);
        }

        free(current);
        current = next;
    }

    return current;
}