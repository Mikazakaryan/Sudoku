#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define UNASSIGNED 0
#define SIZE 9

bool unassignedCell(int grid[SIZE][SIZE], int &row, int &col);
bool legalAssign(int grid[SIZE][SIZE], int row, int col, int value);

bool solve(int grid[SIZE][SIZE]) {
    int row, col;
    if (!unassignedCell(grid, row, col)) {
        return true;
    }
    for (int value = 1; value <= 9; value++) {
        if (legalAssign(grid, row, col, value)) {
            grid[row][col] = value;
            if (solve(grid)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool unassignedCell(int grid[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool existsRow(int grid[SIZE][SIZE], int row, int value) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == value) {
            return true;
        }
    }
    return false;
}

bool existsCol(int grid[SIZE][SIZE], int col, int value) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == value) {
            return true;
        }
    }
    return false;
}

bool existsBox(int grid[SIZE][SIZE], int boxRow, int boxCol, int value) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxRow][col+boxCol] == value) {
                return true;
            }
        }
    }
    return false;
}

bool legalAssign(int grid[SIZE][SIZE], int row, int col, int value) {
    return !existsRow(grid, row, value) && !existsCol(grid, col, value) && !existsBox(grid, row-row%3, col-col%3, value);
}

void drawGrid(int grid[SIZE][SIZE]) {
    printf("----------------------\n");
    for (int row = 0; row < SIZE; row++) {
        printf("|");
        for (int col = 0; col < SIZE; col++) {
            printf("%2d", grid[row][col]);
            if ((col+1) % 3 == 0) printf("|");
        }
        printf("\n");
        if ((row+1) % 3 == 0) {
                printf("----------------------\n");
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        int row = rand() % 10;
        int col = rand() % 10;
        int val = rand() % 10;
        if (legalAssign(grid, row, col, val))
            grid[row][col] = val;
    }
    // printf("Initial grid:\n");
    //   drawGrid(grid);
    // printf("Solution:\n");

    if (solve(grid) == true) {
        drawGrid(grid);
    } else {
      main();
    }

    return 0;
}
