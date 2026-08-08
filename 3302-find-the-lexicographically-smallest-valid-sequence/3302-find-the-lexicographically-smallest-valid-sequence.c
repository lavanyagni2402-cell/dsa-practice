/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);

    // match_len[i] = longest suffix of word2 matchable as a subsequence of word1[i:]
    int* match_len = (int*)malloc((n1 + 1) * sizeof(int));
    int p = n2;
    match_len[n1] = n2 - p; // = 0
    for (int i = n1 - 1; i >= 0; i--) {
        if (p > 0 && word1[i] == word2[p - 1]) {
            p--;
        }
        match_len[i] = n2 - p;
    }

    int* result = (int*)malloc(n2 * sizeof(int));
    int i = 0, j = 0;
    int used_change = 0;

    while (j < n2) {
        if (i >= n1) {
            free(match_len);
            free(result);
            *returnSize = 0;
            return (int*)malloc(0); // no valid sequence
        }
        if (word1[i] == word2[j]) {
            result[j] = i;
            i++;
            j++;
        } else if (!used_change && match_len[i + 1] >= n2 - j - 1) {
            result[j] = i;          // use the one allowed change here
            used_change = 1;
            i++;
            j++;
        } else {
            i++;                    // skip, keep looking for this j
        }
    }

    free(match_len);
    *returnSize = n2;
    return result;
}