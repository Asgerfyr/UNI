#pragma once
#include <vector>
#include <ostream>
#include <string>
#include "cell.h"
#include "matrix.h"



class Board{
    public:
    Board(int cols, int rows);

    bool place(int col, bool player1);

    int get(int col, int row);

    int get_n_cols()const;
    int get_n_rows()const;

    int get_last_play_col()const;
    int get_last_play_row()const;

    std::string to_string()const;

    Matrix<Cell>& get_matrix(); 

    std::vector<float> get_board_in_vec();

    friend std::ostream& operator<<(std::ostream &os, const Board &board);


    private:
    Matrix<Cell> _board;

    int _last_play[2];

};

std::ostream& operator<<(std::ostream &os, const Board &board);
