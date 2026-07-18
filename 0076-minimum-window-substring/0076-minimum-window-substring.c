#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    static char result[100005];

    int need[128] = {0};
    int window[128] = {0};

    int required = 0;

    for (int i = 0; t[i]; i++) {
        if (need[(int)t[i]] == 0)
            required++;
        need[(int)t[i]]++;
    }

    int formed = 0;
    int left = 0;
    int minLen = INT_MAX;
    int start = 0;

    for (int right = 0; s[right]; right++) {
        char c = s[right];
        window[(int)c]++;

        if (need[(int)c] && window[(int)c] == need[(int)c])
            formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char ch = s[left];
            window[(int)ch]--;

            if (need[(int)ch] && window[(int)ch] < need[(int)ch])
                formed--;

            left++;
        }
    }

    if (minLen == INT_MAX) {
        result[0] = '\0';
        return result;
    }

    strncpy(result, s + start, minLen);
    result[minLen] = '\0';

    return result;
}
