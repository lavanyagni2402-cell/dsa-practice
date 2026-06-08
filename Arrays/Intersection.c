#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int maxSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxSize * sizeof(int));

    int count = 0;

    for(int i = 0; i < nums1Size; i++) {

        int exists = 0;

        for(int k = 0; k < count; k++) {
            if(result[k] == nums1[i]) {
                exists = 1;
                break;
            }
        }

        if(exists)
            continue;

        for(int j = 0; j < nums2Size; j++) {
            if(nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                count++;
                break;
            }
        }
    }

    *returnSize = count;
    return result;
}

int main() {

    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int nums1[n1];

    printf("Enter elements of first array:\n");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int nums2[n2];

    printf("Enter elements of second array:\n");
    for(int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    int returnSize;

    int* result = intersection(nums1, n1, nums2, n2, &returnSize);

    printf("Intersection: ");

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);

    return 0;
}