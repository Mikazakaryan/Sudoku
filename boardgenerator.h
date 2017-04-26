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
    int get_board(int i, int j);
    int get_board_for_game(int i, int j);

private:
    int m_number_of_given_amounts;
    int m_grid_for_game[9][9];
    int m_grid[9][9];
};

#endif // BOARDGENERATOR_H
