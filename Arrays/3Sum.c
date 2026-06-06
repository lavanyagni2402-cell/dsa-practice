/* 3Sum is a problem where you find all groups of three numbers in an array that add up to **0**.
Each group should be unique, with no duplicate triplets in the answer.
For example, in `[-1, 0, 1, 2, -1, -4]`, the valid triplets are `[-1, -1, 2]` and `[-1, 0, 1]`.
*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    int maxTriplets = numsSize * numsSize;

    int** result = (int**)malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxTriplets * sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            long sum = (long)nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                result[*returnSize] = (int*)malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int *returnColumnSizes;

    int **result = threeSum(nums, n, &returnSize, &returnColumnSizes);

    printf("\nTriplets:\n");

    for(int i = 0; i < returnSize; i++) {
        printf("[");
        for(int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if(j < returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }

    for(int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}