#include "boardgenerator.h"

boardGenerator::boardGenerator()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int numarr1[] = { 1,2,3,4,5,6,7,8,9 };
    for (int i = 8; i >= 0; i--){
        int pos = qrand() % (i + 1);
        m_grid[0][i] = numarr1[pos];
        for (int j = pos; j<i; j++){
            numarr1[j] = numarr1[j + 1];
        }
    }


    for (int i = 1; i < 9; i++){
        for (int j = 0; j < 9; j++){
            m_grid[i][j] = 0;
        }
    }

    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            m_gridForGame[row][col] = 0;
        }
    }

    if (SolveSudoku(m_grid) == true){
        int count = 1;
        int irand;
        int jrand;

        while (count <= 30){
            irand = qrand() % 9;
            jrand = qrand() % 9;
            m_gridForGame[irand][jrand] = m_grid[irand][jrand];
            ++count;
        }
    }
    else
        boardGenerator();
}

bool boardGenerator::SolveSudoku(int m_grid[9][9]){
    int row, col;

    if (!FindUnassignedLocation(m_grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(m_grid, row, col, num))
        {
            m_grid[row][col] = num;

            if (SolveSudoku(m_grid))
                return true;

            m_grid[row][col] = 0;
        }
    }
    return false;
}

bool boardGenerator::FindUnassignedLocation(int m_grid[9][9], int &row, int &col){
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (m_grid[row][col] == 0)
                return true;
    return false;
}

bool boardGenerator::UsedInRow(int m_grid[9][9], int row, int num){
    for (int col = 0; col < 9; col++)
        if (m_grid[row][col] == num)
            return true;
    return false;
}

bool boardGenerator::UsedInCol(int m_grid[9][9], int col, int num){
    for (int row = 0; row < 9; row++)
        if (m_grid[row][col] == num)
            return true;
    return false;
}

bool boardGenerator::UsedInBox(int m_grid[9][9], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (m_grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool boardGenerator::isSafe(int m_grid[9][9], int row, int col, int num){
    return !UsedInRow(m_grid, row, num) &&
        !UsedInCol(m_grid, col, num) &&
        !UsedInBox(m_grid, row - row % 3, col - col % 3, num);
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
