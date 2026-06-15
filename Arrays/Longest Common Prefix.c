#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0)
        return "";

    for (int i = 0; strs[0][i] != '\0'; i++) {

        char ch = strs[0][i];

        for (int j = 1; j < strsSize; j++) {

            if (strs[j][i] != ch) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}

int main() {

    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;

    char *result = longestCommonPrefix(strs, strsSize);

    printf("Longest Common Prefix: %s\n", result);

    return 0;
}
char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0)
        return "";

    for (int i = 0; strs[0][i] != '\0'; i++) {

        char ch = strs[0][i];

        for (int j = 1; j < strsSize; j++) {

            if (strs[j][i] != ch) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}