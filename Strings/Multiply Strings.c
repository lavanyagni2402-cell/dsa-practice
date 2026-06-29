/* LeetCode 43. Multiply Strings

Given two non-negative integers as strings (num1 and num2), return their product as a string.

Do not convert the strings to integers directly.

Example
Input:
num1 = "123"
num2 = "456"

Output:
"56088"
Idea (Grade School Multiplication)

Multiply exactly like you do by hand.

For each digit:

Multiply one digit from num1 with one digit from num2.
Add the result to the correct position in an array.
Handle carries.
Convert the array to a string. 
Example
      1 2 3
×     4 5 6
-------------
        738
      615
    492
-------------
    56088

Instead of writing on paper, we store the digits in an array.*/

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