#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    char s[] = "PAYPALISHIRING";
    int rows = 3;

    char *ans = convert(s, rows);

    printf("%s\n", ans);

    free(ans);

    return 0;
}

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        char *ans = (char*)malloc((len + 1) * sizeof(char));
        strcpy(ans, s);
        return ans;
    }

    char **rows = (char**)malloc(numRows * sizeof(char*));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int curRow = 0;
    int down = 1;

    for (int i = 0; i < len; i++) {
        int rowLen = strlen(rows[curRow]);
        rows[curRow][rowLen] = s[i];
        rows[curRow][rowLen + 1] = '\0';

        if (curRow == 0)
            down = 1;
        else if (curRow == numRows - 1)
            down = 0;

        if (down)
            curRow++;
        else
            curRow--;
    }

    char *result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }

    free(rows);

    return result;
}