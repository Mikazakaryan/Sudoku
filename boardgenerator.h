#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <QTime>
#include <QVector>


class boardGenerator
{
public:
    boardGenerator();
    ~boardGenerator();
    bool unassignedCell(int grid[9][9], int &row, int &col);
    bool legalAssign(int grid[9][9], int row, int col, int value);
    bool fill(int grid[9][9]);
    bool existsRow(int grid[9][9], int row, int value);
    bool existsCol(int grid[9][9], int col, int value);
    bool existsBox(int grid[9][9], int boxRow, int boxCol, int value);
    int getBoard(int i, int j);
    int getBoardForGame(int i, int j);

private:
    int m_numberOfGivenAmounts;
    int m_gridForGame[9][9] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    int m_grid[9][9] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
};

#endif // BOARDGENERATOR_H
