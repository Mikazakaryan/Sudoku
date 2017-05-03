#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <QTime>


class boardGenerator
{
public:
    boardGenerator();
    ~boardGenerator();
    bool SolveSudoku(int grid[9][9]);
    bool FindUnassignedLocation(int grid[9][9], int &row, int &col);
    bool UsedInRow(int grid[9][9], int row, int num);
    bool UsedInCol(int grid[9][9], int col, int num);
    bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num);
    bool isSafe(int grid[9][9], int row, int col, int num);
    int getBoard(int i, int j);
    int getBoardForGame(int i, int j);

private:
    int m_grid[9][9];
    int m_gridForGame[9][9];

};

#endif // BOARDGENERATOR_H
