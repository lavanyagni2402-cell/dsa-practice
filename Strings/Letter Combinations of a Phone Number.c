/* LeetCode 17- Letter Combinations of a Phone Number
Idea (Backtracking)

Each digit maps to several letters:

2 -> abc
3 -> def
4 -> ghi
5 -> jkl
6 -> mno
7 -> pqrs
8 -> tuv
9 -> wxyz

For every digit:

Pick one letter.
Move to the next digit.
When all digits are processed, store the formed string.

This is a classic backtracking (DFS) problem.*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {

    char digits[] = "23";
    int size;

    char **ans = letterCombinations(digits, &size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }

    free(ans);

    return 0;
}

char *map[] = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int index, char *current,
               char **result, int *returnSize) {

    if (digits[index] == '\0') {
        current[index] = '\0';
        result[*returnSize] = (char *)malloc((strlen(current) + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {

    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

    int len = strlen(digits);

    char **result = (char **)malloc(1000 * sizeof(char *));
    char current[len + 1];

    backtrack(digits, 0, current, result, returnSize);

    return result;
}