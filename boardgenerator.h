#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
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
    void body();
    QVector <int> get_board();
    QVector <int> get_board_for_game();

private:
    int m_number_of_given_amounts;
    int m_grid_for_game[9][9];
    int m_grid[9][9];
    QVector <int> m_board;
    QVector <int> m_board_for_game;

};

#endif // BOARDGENERATOR_H
