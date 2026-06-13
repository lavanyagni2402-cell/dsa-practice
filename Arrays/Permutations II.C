/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

int main() {
    int nums[] = {1, 1, 2};
    int numsSize = 3;

    int returnSize;
    int* returnColumnSizes;

    int** result = permuteUnique(nums,
                                 numsSize,
                                 &returnSize,
                                 &returnColumnSizes);

    printf("Unique Permutations:\n");

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < numsSize; j++) {
            printf("%d", result[i][j]);
            if (j < numsSize - 1)
                printf(", ");
        }
        printf("]\n");
    }

    for (int i = 0; i < returnSize; i++)
        free(result[i]);

    free(result);
    free(returnColumnSizes);

    return 0;
}
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* nums, int numsSize,
               int* used,
               int* current,
               int depth,
               int*** result,
               int* returnSize,
               int* capacity) {

    if (depth == numsSize) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result,
                              (*capacity) * sizeof(int *));
        }

        (*result)[*returnSize] =
            malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++)
            (*result)[*returnSize][i] = current[i];

        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {

        if (used[i])
            continue;

        // Skip duplicates
        if (i > 0 &&
            nums[i] == nums[i - 1] &&
            !used[i - 1])
            continue;

        used[i] = 1;
        current[depth] = nums[i];

        backtrack(nums, numsSize, used, current,
                  depth + 1,
                  result, returnSize, capacity);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize,
                    int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    int capacity = 100;
    int** result = malloc(capacity * sizeof(int*));

    int* used = calloc(numsSize, sizeof(int));
    int* current = malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, used, current, 0,
              &result, returnSize, &capacity);

    *returnColumnSizes =
        malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(used);
    free(current);

    return result;
}