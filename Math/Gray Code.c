/*LeetCode 89- Gray Code

A Gray code sequence of n bits has 2^n integers where adjacent values differ by exactly one bit.

Key Formula- For a number i, its Gray code is:

gray=i⊕(i>>1)

where ⊕ is XOR*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;

    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        ans[i] = i ^ (i >> 1);
    }

    return ans;
}

int main() {
    int n = 2;
    int size;

    int *result = grayCode(n, &size);

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}