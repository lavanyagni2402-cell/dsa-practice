char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    char* ans = malloc((n + 1) * sizeof(char));
    int len = 0;

    for (int i = 0; i < n; i++) {
        int t = target[i] - 'a';

        // Try to use the same character as target
        if (count[t] > 0) {
            count[t]--;
            ans[len++] = target[i];
        } 
        else {
            // First try to make the current position greater
            for (int k = t + 1; k < 26; k++) {
                if (count[k] > 0) {
                    count[k]--;
                    ans[len++] = 'a' + k;

                    // Put remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {
                        while (count[c] > 0) {
                            ans[len++] = 'a' + c;
                            count[c]--;
                        }
                    }

                    ans[len] = '\0';
                    return ans;
                }
            }

            // Cannot make current position greater,
            // so backtrack to an earlier position
            for (int j = i - 1; j >= 0; j--) {
                int prev = ans[j] - 'a';

                count[prev]++;
                len--;

                int tj = target[j] - 'a';

                // Try to make this earlier position greater
                for (int k = tj + 1; k < 26; k++) {
                    if (count[k] > 0) {
                        count[k]--;
                        ans[len++] = 'a' + k;

                        // Append remaining characters in sorted order
                        for (int c = 0; c < 26; c++) {
                            while (count[c] > 0) {
                                ans[len++] = 'a' + c;
                                count[c]--;
                            }
                        }

                        ans[len] = '\0';
                        return ans;
                    }
                }
            }

            free(ans);
            return "";
        }
    }

    // s can form exactly target, but we need STRICTLY greater.
    // Backtrack from the last position.
    for (int j = n - 1; j >= 0; j--) {
        int prev = ans[j] - 'a';

        count[prev]++;
        len--;

        int tj = target[j] - 'a';

        for (int k = tj + 1; k < 26; k++) {
            if (count[k] > 0) {
                count[k]--;
                ans[len++] = 'a' + k;

                for (int c = 0; c < 26; c++) {
                    while (count[c] > 0) {
                        ans[len++] = 'a' + c;
                        count[c]--;
                    }
                }

                ans[len] = '\0';
                return ans;
            }
        }
    }

    free(ans);
    return "";
}