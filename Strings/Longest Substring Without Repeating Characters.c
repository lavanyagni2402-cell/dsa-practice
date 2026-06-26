#include <string.h>
#include <stdio.h>

int main() {
    char s[] = "abcabcbb";

    printf("%d\n", lengthOfLongestSubstring(s));

    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];

    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        if (lastIndex[(unsigned char)s[right]] >= left)
            left = lastIndex[(unsigned char)s[right]] + 1;

        lastIndex[(unsigned char)s[right]] = right;

        int len = right - left + 1;

        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}