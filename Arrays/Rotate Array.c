/* LeetCode 189. Rotate Array

Rotate the array to the right by k steps.

Example:

nums = [1,2,3,4,5,6,7]
k = 3

Output:
[5,6,7,1,2,3,4]
Optimal Approach (Reverse)
Reverse the entire array.
Reverse the first k elements.
Reverse the remaining elements.
1 2 3 4 5 6 7
↓ reverse all
7 6 5 4 3 2 1
↓ reverse first k=3
5 6 7 4 3 2 1
↓ reverse rest
5 6 7 1 2 3 4 */
#include <stdio.h>

void reverse(int* nums, int left, int right) {
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int n = sizeof(nums) / sizeof(nums[0]);

    rotate(nums, n, 3);

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}