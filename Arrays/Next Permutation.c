#include <stdio.h>

void reverse(int* nums, int start, int end);
void nextPermutation(int* nums, int numsSize);

int main() {

    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, n);

    printf("Next Permutation: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {

    int i = numsSize - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {

        int j = numsSize - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    reverse(nums, i + 1, numsSize - 1);
}