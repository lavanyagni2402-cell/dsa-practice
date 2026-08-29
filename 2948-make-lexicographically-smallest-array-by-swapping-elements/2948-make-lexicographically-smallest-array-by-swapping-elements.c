#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int comparePairs(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;

    if (p1->value != p2->value)
        return p1->value - p2->value;

    return p1->index - p2->index;
}

int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* lexicographicallySmallestArray(
    int* nums,
    int numsSize,
    int limit,
    int* returnSize
) {
    *returnSize = numsSize;

    Pair *arr = malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Sort by value
    qsort(arr, numsSize, sizeof(Pair), comparePairs);

    int start = 0;

    while (start < numsSize) {
        int end = start;

        // Find one connected group
        while (end + 1 < numsSize &&
               arr[end + 1].value - arr[end].value <= limit) {
            end++;
        }

        int size = end - start + 1;

        // Store values and indices of this group
        int *values = malloc(size * sizeof(int));
        int *indices = malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            values[i] = arr[start + i].value;
            indices[i] = arr[start + i].index;
        }

        // Sort indices
        qsort(indices, size, sizeof(int), compareInt);
        for (int i = 0; i < size; i++) {
            nums[indices[i]] = values[i];
        }

        free(values);
        free(indices);

        start = end + 1;
    }

    free(arr);

    return nums;
}