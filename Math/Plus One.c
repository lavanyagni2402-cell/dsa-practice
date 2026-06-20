//leetcode problem 67 

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        
        digits[i] = 0;
    }

    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    result[0] = 1;

    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }

    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    int digits[] = {9, 9, 9};
    int returnSize;

    int* result = plusOne(digits, 3, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    if (result != digits)
        free(result);

    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        
        digits[i] = 0;
    }

    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    result[0] = 1;

    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }

    *returnSize = digitsSize + 1;
    return result;
}