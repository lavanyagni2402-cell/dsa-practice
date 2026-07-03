#include <stdio.h>

int jump(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", jump(nums, n));

    return 0;
}