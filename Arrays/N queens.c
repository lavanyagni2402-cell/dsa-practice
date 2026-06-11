#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ***results;
int solutionCount;
int capacity;

bool isSafe(int *queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        int qcol = queens[i];

        if (qcol == col)
            return false;

        if (abs(qcol - col) == abs(i - row))
            return false;
    }
    return true;
}

void addSolution(int *queens, int n) {
    if (solutionCount == capacity) {
        capacity *= 2;
        results = realloc(results, capacity * sizeof(char **));
    }

    char **board = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++)
            board[i][j] = '.';

        board[i][queens[i]] = 'Q';
        board[i][n] = '\0';
    }

    results[solutionCount++] = board;
}

void backtrack(int *queens, int row, int n) {
    if (row == n) {
        addSolution(queens, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            backtrack(queens, row + 1, n);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    solutionCount = 0;
    capacity = 100;

    results = malloc(capacity * sizeof(char **));

    int *queens = malloc(n * sizeof(int));

    backtrack(queens, 0, n);

    free(queens);

    *returnSize = solutionCount;

    *returnColumnSizes = malloc(solutionCount * sizeof(int));

    for (int i = 0; i < solutionCount; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return results;
}
#include <stdio.h>

// ----- keep your existing solveNQueens code above -----

int main() {
    int n = 4;
    int returnSize;
    int *returnColumnSizes;

    char ***result = solveNQueens(n, &returnSize, &returnColumnSizes);

    printf("Number of solutions: %d\n\n", returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("Solution %d:\n", i + 1);

        for (int j = 0; j < n; j++) {
            printf("%s\n", result[i][j]);
        }

        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < n; j++) {
            free(result[i][j]);
        }
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}