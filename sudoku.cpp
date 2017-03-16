#include "./sudoku.h"

bool fill(int grid[SIZE][SIZE]) {
  int row, col;
  if (!unassignedCell(grid, row, col)) {
    return true;
  }
  for (int value = 1; value <= 9; value++) {
    if (legalAssign(grid, row, col, value)) {
      grid[row][col] = value;
      if (fill(grid)) {
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

int chose_dificulty(){
  srand(time(NULL));
  int number_of_given_amounts = 0;
  printf("For easy press - 1\n");
  printf("For medium press - 2\n");
  printf("For hard press - 3\n");
  printf("For evil press - 4\n");
  int choise;
  do{
    std::cin>>choise;
    if(choise < 1 || choise > 4){
     printf("Wrong number do it aggain\n");
    }
  }while(choise < 1 || choise > 4);
  switch (choise) {
    case 1:
      number_of_given_amounts = rand() % 10 + 35;
      break;
    case 2:
      number_of_given_amounts = rand() % 5 + 45;
      break;
    case 3:
      number_of_given_amounts = rand() % 10 + 50;
      break;
    case 4:
      number_of_given_amounts = rand() % 10 + 55;
      break;
  }
  return number_of_given_amounts;
}

void body() {
  int grid[SIZE][SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0}};
  int number_of_given_amounts;
  srand(time(NULL));
  for (int i = 0; i < 30; i++) {
    int row = rand() % 9;
    int col = rand() % 9;
    int val = rand() % 9 + 1;
    if (legalAssign(grid, row, col, val))
      grid[row][col] = val;
  }
  if (fill(grid) == true) {
    drawGrid(grid);
    number_of_given_amounts = chose_dificulty();
    for (size_t i = 0; i < number_of_given_amounts; i++) {
      int row = rand() % 9;
      int col = rand() % 9;
      if(grid[row][col] != 0){
        grid[row][col] = 0;
      }else{
        i--;
      }
    }
    drawGrid(grid);
  } else {
    body();
  }
}

int main() {
  body();
  return 0;
}
