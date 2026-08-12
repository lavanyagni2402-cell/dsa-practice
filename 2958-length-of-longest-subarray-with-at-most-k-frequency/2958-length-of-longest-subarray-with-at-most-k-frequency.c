int maxSubarrayLength(int* nums, int numsSize, int k) {
    int size = 1;
    while (size < numsSize * 2)
        size *= 2;

    int *keys = calloc(size, sizeof(int));
    int *freq = calloc(size, sizeof(int));

    int left = 0;
    int ans = 0;

    // Find index for a value
    #define HASH(x) ((unsigned int)(x) * 2654435761u & (size - 1))

    // Function-like lookup using linear probing
    #define GET_INDEX(x) ({ \
        int idx = HASH(x); \
        while (keys[idx] != 0 && keys[idx] != (x)) \
            idx = (idx + 1) & (size - 1); \
        if (keys[idx] == 0) \
            keys[idx] = (x); \
        idx; \
    })

    for (int right = 0; right < numsSize; right++) {
        int idx = GET_INDEX(nums[right]);
        freq[idx]++;

        while (freq[idx] > k) {
            int leftIdx = GET_INDEX(nums[left]);
            freq[leftIdx]--;
            left++;

            idx = GET_INDEX(nums[right]);
        }

        int len = right - left + 1;

        if (len > ans)
            ans = len;
    }

    free(keys);
    free(freq);

    return ans;
}