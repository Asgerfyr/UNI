#include "cell.h"
#include <stdexcept>


#include <iostream>


Cell::Cell():_filled{false},_player1{false}{}

void Cell::set(bool player1_){
    if(_filled) throw std::logic_error("This cell has already been filled, use force fill, instead");
    _filled = true;
    _player1 = player1_;
}

void Cell::force_set(bool player1_){
    _filled = true;
    _player1 = player1_;
}

void Cell::reset(){
     _filled = false;
    _player1 = 0;
}

int Cell::get(){
    if(!_filled) return -1;
    return _player1;
}

bool Cell::get_filled(){
    return _filled;
}


std::string Cell::to_string()const{
    std::string s = "\033[30m#\033[0m";
    
    if(!_filled)return s;
    
    if(!_player1){
        s = "\033[1;32m#\033[0m";
    }else{
        s = "\033[1;31m#\033[0m";
    }
    
    return s;
}