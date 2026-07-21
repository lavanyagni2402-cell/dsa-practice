#define MAX 25

int memo[MAX][MAX];

int solve(char *s, char *p, int i, int j) {

    if (memo[i][j] != -1)
        return memo[i][j];

    if (p[j] == '\0')
        return memo[i][j] = (s[i] == '\0');

    int firstMatch = (s[i] != '\0' &&
                     (s[i] == p[j] || p[j] == '.'));

    if (p[j + 1] == '*') {

        return memo[i][j] =
               solve(s, p, i, j + 2) ||
               (firstMatch && solve(s, p, i + 1, j));

    }

    return memo[i][j] =
           firstMatch &&
           solve(s, p, i + 1, j + 1);
}

bool isMatch(char* s, char* p) {

    memset(memo, -1, sizeof(memo));

    return solve(s, p, 0, 0);

}