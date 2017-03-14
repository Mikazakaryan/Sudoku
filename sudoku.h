#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#define UNASSIGNED 0
#define SIZE 9

bool unassignedCell(int grid[SIZE][SIZE], int &row, int &col);
bool legalAssign(int grid[SIZE][SIZE], int row, int col, int value);
bool fill(int grid[SIZE][SIZE]);
bool existsRow(int grid[SIZE][SIZE], int row, int value);
bool existsCol(int grid[SIZE][SIZE], int col, int value);
bool existsBox(int grid[SIZE][SIZE], int boxRow, int boxCol, int value);
void drawGrid(int grid[SIZE][SIZE]);
int chose_dificulty();
void body();
