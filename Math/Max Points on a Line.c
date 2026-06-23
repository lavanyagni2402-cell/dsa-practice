#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1[] = {1,1};
    int r2[] = {2,2};
    int r3[] = {3,3};

    int* points[] = {r1, r2, r3};

    int colSize = 2;

    printf("%d\n", maxPoints(points, 3, &colSize));

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2)
        return pointsSize;

    int ans = 0;

    for (int i = 0; i < pointsSize; i++) {

        int slopes[301][2];
        int counts[301];
        int unique = 0;

        for (int k = 0; k < 301; k++)
            counts[k] = 0;

        for (int j = i + 1; j < pointsSize; j++) {

            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            }

            int found = -1;

            for (int s = 0; s < unique; s++) {
                if (slopes[s][0] == dx && slopes[s][1] == dy) {
                    found = s;
                    break;
                }
            }

            if (found == -1) {
                slopes[unique][0] = dx;
                slopes[unique][1] = dy;
                counts[unique] = 1;
                unique++;
            } else {
                counts[found]++;
            }
        }

        int localMax = 0;

        for (int s = 0; s < unique; s++) {
            if (counts[s] > localMax)
                localMax = counts[s];
        }

        if (localMax + 1 > ans)
            ans = localMax + 1;
    }

    return ans;
}