#include <vector>
#include "ai.h"
#include "game.h"

class Simulator{

    public:
    Simulator(int cols, int rows, std::vector<int> hidden_layers, int amount_ai_total = 1500);

    void simulate(int generations, bool visual);

    void visual_progress_bar(int gen, int total_gen);

    
    void run_games();
    
    void game_play_round(int index_ai);
    
    void rank_ai();
    
    void generate_ais();
    
    void format_board_input(std::vector<float>& input);
    
    void play_top_ai();

    void set_amount_to_keep(int amount_to_keep);
    void set_amount_copy_of_kept(int amount_copy_of_kept);
    void set_amount_ai_total(int amount_ai_total);
    void set_mutation_multiplier(float mutation_multiplier);


    private:

    bool ready_for_training = 1;

    int _inputs;

    int _cols;
    int _rows;

    int _amount_to_keep = 20;
    int _amount_copy_of_kept = 50;
    int _amount_ai_total = 1500;

    float _mutation_multiplier = 1;

    Game _game;

    std::vector<int> _hidden_layers;

    std::vector<Ai> _ais;
    std::vector<int> _ais_sorted_index;

    

};