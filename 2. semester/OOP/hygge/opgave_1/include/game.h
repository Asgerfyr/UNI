#include <string>
#include "board.h"


class Game{

    public:
    Game(int cols, int rows);


    void reset();
    bool place(int col);
    void calculate_score();

    void set_calc_score_on_place(bool calc_score_on_place);

    std::string to_string()const;

    void interface();

    friend std::ostream& operator<<(std::ostream &os, const Game &game);

    Board& get_board(); 
    bool get_turn()const; 
    int get_player0_points()const; 
    int get_player1_points()const; 
    int get_player0_wins()const; 
    int get_player1_wins()const; 
    int get_player0_last_play()const; 
    int get_player1_last_play()const; 



    private:

    Board _board;

    bool player1_turn;

    int _player0_points;
    int _player1_points;
    
    int _player0_wins;
    int _player1_wins;


    int _player0_last_play;
    int _player1_last_play;

    bool _calc_score_on_place;

    bool _finish_on_win;

    void calc_score_on_place();

};

std::ostream& operator<<(std::ostream &os, const Game &game);
