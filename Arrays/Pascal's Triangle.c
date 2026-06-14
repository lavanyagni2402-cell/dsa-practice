/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int main() {
    int numRows = 5;

    int returnSize;
    int* returnColumnSizes;

    int** result = generate(numRows,
                            &returnSize,
                            &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    *returnSize = numRows;

    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {

        (*returnColumnSizes)[i] = i + 1;

        result[i] = (int*)malloc((i + 1) * sizeof(int));

        result[i][0] = 1;
        result[i][i] = 1;

        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}