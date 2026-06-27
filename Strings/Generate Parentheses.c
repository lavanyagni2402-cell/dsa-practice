/* LeetCode 22- Generate Parentheses
Idea (Backtracking)

At any point:

You can add '(' if you haven't used all n opening brackets.
You can add ')' only if the number of closing brackets used is less than the number of opening brackets used.

This ensures every generated string is valid. */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    int size;

    char **ans = generateParenthesis(3, &size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }

    free(ans);

    return 0;
}

void backtrack(char **result, int *returnSize,
               char *current, int pos,
               int open, int close, int n) {

    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current,
                  pos + 1, open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current,
                  pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {

    int maxSize = 1430;    // Maximum for n <= 8

    char **result = (char **)malloc(maxSize * sizeof(char *));
    char current[2 * n + 1];

    *returnSize = 0;

    backtrack(result, returnSize, current,
              0, 0, 0, n);

    return result;
}