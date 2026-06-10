#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    qsort(nums, n, sizeof(int), compare);

    printf("Quadruplets:\n");

    for (int i = 0; i < n - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)nums[i] +
                                nums[j] +
                                nums[left] +
                                nums[right];

                if (sum == target) {

                    printf("[%d, %d, %d, %d]\n",
                           nums[i], nums[j],
                           nums[left], nums[right]);

                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return 0;
}