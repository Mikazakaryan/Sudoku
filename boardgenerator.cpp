#include "boardgenerator.h"

boardGenerator::boardGenerator()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    for (int i = 0; i < 30; i++) {
      int row = qrand() % 9;
      int col = qrand() % 9;
      int val = qrand() % 9 + 1;
      if (legalAssign(m_grid, row, col, val)){
        m_grid[row][col] = val;
      }
    }
    if (fill(m_grid) == true) {
      for (size_t i = 0; i < 9; i++) {
          for (size_t j = 0; j < 9; j++) {
            m_gridForGame[i][j] = m_grid[i][j];
          }
      }
      //m_numberOfGivenAmounts = qrand() % 10 + 45;
      //for testing
      m_numberOfGivenAmounts = 1;
      for (int i = 0; i < m_numberOfGivenAmounts; i++) {
        int row = qrand() % 9;
        int col = qrand() % 9;
        if(m_gridForGame[row][col] != 0){
          m_gridForGame[row][col] = 0;
        }else{
          i--;
        }
      }
    } else {
      boardGenerator();
    }
}

bool boardGenerator::fill(int m_grid[9][9]) {
  int row, col;
  if (!unassignedCell(m_grid, row, col)) {
    return true;
  }
  for (int value = 1; value <= 9; value++) {
    if (legalAssign(m_grid, row, col, value)) {
      m_grid[row][col] = value;
      if (fill(m_grid)) {
        return true;
      }
      m_grid[row][col] = 0;
    }
  }
  return false;
}

bool boardGenerator::unassignedCell(int m_grid[9][9], int &row, int &col) {
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (m_grid[row][col] == 0) {
        return true;
      }
    }
  }
  return false;
}

bool boardGenerator::existsRow(int m_grid[9][9], int row, int value) {
  for (int col = 0; col < 9; col++) {
    if (m_grid[row][col] == value) {
      return true;
    }
  }
  return false;
}

bool boardGenerator::existsCol(int m_grid[9][9], int col, int value) {
  for (int row = 0; row < 9; row++) {
    if (m_grid[row][col] == value) {
      return true;
    }
  }
  return false;
}

bool boardGenerator::existsBox(int m_grid[9][9], int boxRow, int boxCol, int value) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (m_grid[row+boxRow][col+boxCol] == value) {
        return true;
      }
    }
  }
  return false;
}

bool boardGenerator::legalAssign(int m_grid[9][9], int row, int col, int value) {
  return !existsRow(m_grid, row, value) && !existsCol(m_grid, col, value) && !existsBox(m_grid, row-row%3, col-col%3, value);
}

int boardGenerator::getBoard(int i, int j){
    return m_grid[i][j];
}

int boardGenerator::getBoardForGame(int i, int j){
    return m_gridForGame[i][j];
}

boardGenerator::~boardGenerator()
{
}
