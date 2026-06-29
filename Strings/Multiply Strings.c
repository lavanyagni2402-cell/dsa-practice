#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {

    char num1[] = "123";
    char num2[] = " 456";

    char *ans = multiply(num1, num2);

    printf("%s\n", ans);

    free(ans);

    return 0;
}

char* multiply(char* num1, char* num2) {

    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char *ans = (char*)malloc(2);
        strcpy(ans, "0");
        return ans;
    }

    int n = strlen(num1);
    int m = strlen(num2);

    int result[n + m];

    for (int i = 0; i < n + m; i++)
        result[i] = 0;

    for (int i = n - 1; i >= 0; i--) {

        for (int j = m - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    char *ans = (char*)malloc(n + m + 1);

    int k = 0;
    int i = 0;

    while (i < n + m && result[i] == 0)
        i++;

    while (i < n + m)
        ans[k++] = result[i++] + '0';

    ans[k] = '\0';

    return ans;
}