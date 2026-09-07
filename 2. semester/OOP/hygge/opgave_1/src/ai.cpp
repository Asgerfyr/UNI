#include "ai.h"

Ai::Ai(int inputs, std::vector<int> layers, int outputs):
    _brain(inputs,layers,outputs){};

int Ai::calc_ai(std::vector<float>& input){
    _brain.calc_brain(input);
    return _brain.get_n_conf_output(0)+1;
}

int Ai::calc_ai(std::vector<float> input,bool save){
    std::vector<float> input_ = input;
    _brain.calc_brain(input);
    return _brain.get_n_conf_output(0)+1;
}

int Ai::get_n_output(int n)const{
    return _brain.get_n_conf_output(n)+1;
}

Ai_Brain& Ai::get_brain(){
    return _brain;
}

void Ai::set_score(int new_score){
    _score = new_score;
}

void Ai::add_score(int new_score){
    _score += new_score;
}

bool Ai::operator<(const Ai& other)const{
    return this->_score < other._score;
}

bool Ai::operator>(const Ai& other)const{
    return this->_score > other._score;
}