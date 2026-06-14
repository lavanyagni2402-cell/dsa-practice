#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize);

int main() {

    int rowIndex = 3;
    int returnSize;

    int* row = getRow(rowIndex, &returnSize);

    printf("Row %d: ", rowIndex);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", row[i]);
    }

    printf("\n");

    free(row);

    return 0;
}

int* getRow(int rowIndex, int* returnSize) {

    *returnSize = rowIndex + 1;

    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));

    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {

        row[i] = 1;

        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}