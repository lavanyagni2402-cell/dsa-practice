#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][100], int rows, int cols, int target) {

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target)
            return true;

        else if (matrix[row][col] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return false;
}

int main() {

    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    printf("Enter matrix elements:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    if(searchMatrix(matrix, rows, cols, target))
        printf("Target found\n");
    else
        printf("Target not found\n");

    return 0;
}