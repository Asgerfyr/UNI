#include <algorithm>
#include <iostream>
#include "simulator.h"


Simulator::Simulator(int cols, int rows, std::vector<int> hidden_layers, int amount_ai_total):_cols{7},_rows{6},_game{cols,rows}, _amount_ai_total{amount_ai_total}{
    _hidden_layers = hidden_layers;

    _inputs = _cols*_rows+1;

    _ais;

    for (int i = 0; i < _amount_ai_total; i++) {
        _ais.emplace_back(Ai(_inputs,hidden_layers,cols));
    }
}

void Simulator::simulate(int generations, bool visual){
    if(!ready_for_training){
        rank_ai();
        generate_ais();
    }

    int visual_update = generations/100;

    if(visual){
        visual_progress_bar(0,generations);
    }

    for(int i = 0; i < generations; i++){
        
        run_games();
        rank_ai();
        generate_ais();


        if(visual && i % visual_update == 0){
            visual_progress_bar(i,generations);
        }
    }

}

void Simulator::visual_progress_bar(int gen, int total_gen){
    std::cout << std::endl << std::endl << std::endl << std::endl;

    std::cout << "Training in progress:" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|";
    
    int fill_amount = (gen*40)/total_gen;
    int p = (gen*100)/total_gen;
    
    for(int i = 0; i < 40; i++){
        if(i < fill_amount){
            std::cout << "\033[1;32m#";
        }else{
            std::cout << "\033[30m#";
        }
    }
    std::cout << "\033[0m";

    std::cout << "|" << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "progress: " << p << "%" << std::endl;

}



void Simulator::run_games(){
    int rounds = _cols*_rows;

    for(int i_ai = 1; i_ai < _ais.size(); i_ai++) {
        _game.reset();
        
        for(int round = 0; round < rounds; round++){
            if(round%2==0){
                game_play_round(0);
            }else{
                game_play_round(i_ai);
            }
        }

        _ais[i_ai].set_score(_game.get_player1_points()-_game.get_player0_points());
        if(i_ai == 1 )_ais[0].set_score(_game.get_player0_points()-_game.get_player1_points());
    }
}

void Simulator::game_play_round(int index_ai){
    bool sec;
    int tries;
    
    std::vector<float> inputs;

    inputs = _game.get_board().get_board_in_vec();

    format_board_input(inputs);
    
    if(!_game.get_turn()){
        inputs.emplace_back(_game.get_player1_last_play());
    }else{
        inputs.emplace_back(_game.get_player0_last_play());
    }

    // std::cout << std::endl;
    // for (auto it = inputs.begin(); it != inputs.end(); ++it) {
    //     std::cout << (*it) << std::endl;
    // }
    // std::cout << std::endl;

    sec = _game.place(_ais[index_ai].calc_ai(inputs));
    
    if(!sec){
        tries = 0;
        for(int i = 1;i < 7;i++){
            sec = _game.place(_ais[index_ai].get_n_output(i));
            if(sec)break;
        }
    }
}

void Simulator::rank_ai(){
    std::nth_element(_ais.begin(), _ais.begin() + _amount_to_keep, 
                  _ais.end(), std::greater<Ai>());
    
    std::sort(_ais.begin(), _ais.begin() + _amount_to_keep, std::greater<Ai>());
}

void Simulator::generate_ais(){
    //generate mutated ai;
    auto it = _ais.begin();
    it += _amount_to_keep;

    for(int n_keep = 0; n_keep < _amount_to_keep; n_keep++){
        for(int n_copy = 0; n_copy < _amount_copy_of_kept; n_copy++){
            (*it).get_brain().copy_brain(_ais[n_keep].get_brain());
            (*it).get_brain().mutate(_mutation_multiplier, _mutation_multiplier);
        }
    }

    while(it!=_ais.end()){
        (*it).get_brain().brain_random();
        ++it;
    }
}





void Simulator::format_board_input(std::vector<float>& input){
    for (auto it = input.begin(); it != input.end(); ++it) {
        if((*it) < 0) (*it) = 0.5;
    }
}




void Simulator::play_top_ai(){
    int rounds = _cols*_rows;

    
    _game.reset();
        
    for(int round = 0; round < rounds; round++){
        if(round%2==0){
            _game.interface();
        }else{
            game_play_round(0);
        }
    }

    std::cout << _game << std::endl;
}



void Simulator::set_amount_to_keep(int amount_to_keep){
    _amount_to_keep = amount_to_keep;
}

void Simulator::set_amount_copy_of_kept(int amount_copy_of_kept){
    _amount_copy_of_kept = amount_copy_of_kept;
}

void Simulator::set_amount_ai_total(int amount_ai_total){
    _amount_ai_total = amount_ai_total;
}

void Simulator::set_mutation_multiplier(float mutation_multiplier){
    _mutation_multiplier = mutation_multiplier;
}
