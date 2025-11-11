#include <stdio.h>

#define SIZE 9

// Checks if all numbers 1-9 appear exactly once in each row
int check_rows(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int seen[SIZE + 1] = {0};
        for (int j = 0; j < SIZE; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) return 0;
            seen[num] = 1;
        }
    }
    return 1;
}

// Checks if all numbers 1-9 appear exactly once in each column
int check_columns(int grid[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        int seen[SIZE + 1] = {0};
        for (int i = 0; i < SIZE; i++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) return 0;
            seen[num] = 1;
        }
    }
    return 1;
}

// Checks if all 3x3 sub-grids contain numbers 1-9 exactly once
int check_subgrids(int grid[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r += 3) {
        for (int c = 0; c < SIZE; c += 3) {
            int seen[SIZE + 1] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = grid[r + i][c + j];
                    if (num < 1 || num > 9 || seen[num]) return 0;
                    seen[num] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    // You can use either this hard-coded example, or change input method for user entry
    int grid[SIZE][SIZE] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    // If you want user input instead, uncomment below:
    /*
    printf("Enter your Sudoku puzzle row-by-row, 9 numbers each, separated by spaces:\n");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            scanf("%d", &grid[i][j]);
    */

    if (check_rows(grid) && check_columns(grid) && check_subgrids(grid))
        printf("VALID SOLUTION\n");
    else
        printf("INVALID SOLUTION\n");

    return 0;
}
