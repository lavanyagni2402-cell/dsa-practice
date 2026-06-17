#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize);

int main() {

    char row0[] = {'5','3','.','.','7','.','.','.','.'};
    char row1[] = {'6','.','.','1','9','5','.','.','.'};
    char row2[] = {'.','9','8','.','.','.','.','6','.'};
    char row3[] = {'8','.','.','.','6','.','.','.','3'};
    char row4[] = {'4','.','.','8','.','3','.','.','1'};
    char row5[] = {'7','.','.','.','2','.','.','.','6'};
    char row6[] = {'.','6','.','.','.','.','2','8','.'};
    char row7[] = {'.','.','.','4','1','9','.','.','5'};
    char row8[] = {'.','.','.','.','8','.','.','7','9'};

    char* board[] = {
        row0,row1,row2,row3,row4,
        row5,row6,row7,row8
    };

    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};

    if (isValidSudoku(board, 9, boardColSize))
        printf("Valid Sudoku\n");
    else
        printf("Invalid Sudoku\n");

    return 0;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.')
                continue;

            int num = board[i][j] - '1';
            int box = (i / 3) * 3 + (j / 3);

            if (rows[i][num] ||
                cols[j][num] ||
                boxes[box][num])
                return false;

            rows[i][num] = 1;
            cols[j][num] = 1;
            boxes[box][num] = 1;
        }
    }

    return true;
}