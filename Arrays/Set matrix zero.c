#include <stdio.h>

void setZeroes(int matrix[][100], int rows, int cols) {

    int rowMark[100] = {0};
    int colMark[100] = {0};

    // Find positions containing 0
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            if(matrix[i][j] == 0) {
                rowMark[i] = 1;
                colMark[j] = 1;
            }
        }
    }

    // Set rows and columns to 0
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            if(rowMark[i] == 1 || colMark[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
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

    setZeroes(matrix, rows, cols);

    printf("\nUpdated Matrix:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}