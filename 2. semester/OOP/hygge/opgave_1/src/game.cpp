#include <vector>
#include <sstream>
#include <iostream>
#include "game.h"


Game::Game(int cols, int rows):
        _board(cols, rows), 
        player1_turn(0),
        _calc_score_on_place(1),
        _finish_on_win(0),
        _player0_points(0),
        _player1_points(0),
        _player0_wins(0),
        _player1_wins(0),
        _player0_last_play(0),
        _player1_last_play(0){}

void Game::reset(){
    std::vector<Cell>& vec = _board.get_matrix().get_matrix_vec();

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        it->reset();
    }

    player1_turn = 0;
    _player0_points = 0;
    _player1_points = 0;
    _player0_wins = 0;
    _player1_wins = 0;
    _player0_last_play = 0;
    _player1_last_play = 0;
}

bool Game::place(int col_){
    if(col_ <= 0 || col_ > _board.get_n_cols()) return false;

    int col = col_-1;
    bool result = _board.place(col,player1_turn);
    
    if(result) {
        if(_calc_score_on_place) calc_score_on_place();
        if (!player1_turn) _player0_last_play = col;
        if (player1_turn) _player1_last_play = col;
        player1_turn = !player1_turn;
    }

    return result;
}


void Game::calc_score_on_place(){

    int n_cols = _board.get_n_cols();
    int n_rows = _board.get_n_rows();

    int score{};

    int score_table[3] = {1,10,100};

    int wins{};
    
    short dir_table[7][2] = {
        {-1,-1},
        {-1, 0},
        {-1, 1},
        { 0, 1},
        { 1, 1},
        { 1, 0},
        { 1,-1}
    };

    int last_play[2];

    last_play[0] = _board.get_last_play_col();
    last_play[1] = _board.get_last_play_row();

    int max_in_a_row = 4; // this means a 4 in a row to win

    for(short dir_check = 0; dir_check < 7; dir_check++){
        int check_col = last_play[0];
        int check_row = last_play[1];

        for(int in_a_row = 2; in_a_row < max_in_a_row+1; in_a_row++){
            check_col += dir_table[dir_check][0];
            check_row += dir_table[dir_check][1];
            if(check_col < 0 || check_col >= n_cols || check_row < 0 || check_row >= n_rows) break;
            if(_board.get(check_col,check_row) != player1_turn)break;

            score += score_table[in_a_row-2];
            if(in_a_row == 4) wins++;

        }
    }

    if(!player1_turn){
        _player0_points += score;
        _player0_wins += wins;
    }
    if(player1_turn){
        _player1_points += score;
        _player1_wins += wins;
    }
}

#include <iostream>

void Game::calculate_score(){

    _player0_points = 0;
    _player0_wins = 0;
    
    _player1_points = 0;
    _player1_wins = 0;

    int n_cols = _board.get_n_cols();
    int n_rows = _board.get_n_rows();

    int scores[2]{};

    int score_table[3] = {1,10,100};

    int wins[2]{};
    
    short dir_table[4][2] = {
        {-1, 1},
        { 0, 1},
        { 1, 1},
        { 1, 0}
        };

    int chack_pos[2];

    int max_in_a_row = 4; // this means a 4 in a row to win

    for(int c = n_cols-1; c >= 0; c--){

        for(int r = n_rows-1; r >= 0; r--){

            chack_pos[0] = c;
            chack_pos[1] = r;
            
            for(int player = 0; player < 2; player++){
                
                if(_board.get(c,r) != player)continue;

                for(short dir_check = 0; dir_check < 4; dir_check++){
                
                    int check_col = chack_pos[0];
                    int check_row = chack_pos[1];

                    for(int in_a_row = 2; in_a_row < max_in_a_row+1; in_a_row++){
                        check_col += dir_table[dir_check][0];
                        check_row += dir_table[dir_check][1];
                        if(check_col < 0 || check_col >= n_cols || check_row < 0 || check_row >= n_rows) break;
                        if(_board.get(check_col,check_row) != player)break;
                        
                        std::cout << "direction: " << std::to_string(dir_check) << std::endl;
                        std::cout << "player: " << std::to_string(player) << std::endl;

                        scores[player] += score_table[in_a_row-2];
                        if(in_a_row == 4) wins[player]++;

                    }
                }
            }
        }
    }

    
    _player0_points += scores[0];
    _player0_wins += wins[0];
    
    _player1_points += scores[1];
    _player1_wins += wins[1];
    
}


std::string Game::to_string()const{
    std::stringstream ss;

    int n_cols = _board.get_n_cols();


    for(int i = 0; i < n_cols; i++) {
        ss << (i+1);
    }
    ss << std::endl;
    
    for(int i = 0; i < n_cols; i++) {
        ss << "v";
    }
    ss << std::endl;

    ss << _board.to_string();

    ss << std::endl;
    
    ss << "player 0 score: " << _player0_points << " wins: " << _player0_wins << std::endl;
    ss << "player 1 score: " << _player1_points << " wins: " << _player1_wins << std::endl;
    
    ss << std::endl;
    
    return ss.str();
}

void Game::interface(){

    while(1){
        std::cout << (*this);

        std::cout << "player " << player1_turn << " turn" << std::endl;
        std::cout << "what colum?" << std::endl;
        int col;

        std::cin >> col;

        bool sec = this->place(col);

        if(sec) break;
    }
}


std::ostream& operator<<(std::ostream &os, const Game &game){
    os << game.to_string();
    return os;
}










Board& Game::get_board(){
    return _board;
}

bool Game::get_turn()const{
    return player1_turn;
}

int Game::get_player0_points()const{
    return _player0_points;
}

int Game::get_player1_points()const{
    return _player1_points;
}

int Game::get_player0_wins()const{
    return _player0_wins;
}

int Game::get_player1_wins()const{
    return _player1_wins;
}

int Game::get_player0_last_play()const{
    return _player0_last_play;
}

int Game::get_player1_last_play()const{
    return _player1_last_play;
}
