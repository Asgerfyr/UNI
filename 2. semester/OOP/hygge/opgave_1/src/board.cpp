#include <ostream>
#include <functional>
#include "board.h"



Board::Board(int cols, int rows):_board(cols,rows){
}

bool Board::place(int col, bool player1){
    int rows = _board.get_n_rows();
    int row = rows-1;
    while(row >= 0){
        if(!(_board.get(col, row).get_filled()))break;
        if(row == 0) return false;
        row--;
    }
    _board.get(col, row).set(player1);

    _last_play[0] = col;
    _last_play[1] = row;
    
    return true;
}

int Board::get(int col, int row){
    return _board.get(col, row).get();
}

int Board::get_n_cols()const{
    return _board.get_n_cols();
}

int Board::get_n_rows()const{
    return _board.get_n_rows();
}

int Board::get_last_play_col()const{
    return _last_play[0];
}

int Board::get_last_play_row()const{
    return _last_play[1];
}



std::string Board::to_string()const{
    return _board.to_string();
}

Matrix<Cell>& Board::get_matrix(){
    return _board;
} 


std::vector<float> Board::get_board_in_vec(){
    std::vector<float> res(_board.get_n_cols()*_board.get_n_rows());
    std::vector<Cell>& board = _board.get_matrix_vec();

    std::transform(board.begin(),board.end(),res.begin(),std::mem_fn(&Cell::get)
    );

    return res;
}


std::ostream& operator<<(std::ostream &os, const Board &board){
    os << board.to_string();
    return os;
}