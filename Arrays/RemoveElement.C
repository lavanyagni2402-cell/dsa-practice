#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int val;
    scanf("%d", &val);

    int k = removeElement(arr, n, val);

    printf("k = %d\n", k);

    for(int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}